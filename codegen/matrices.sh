#!/bin/bash

vec_size=0
mat_size=0

if ((OPTIND == 1)); then
    printf "Usage: -v VECTOR DIMENSION -m MATRIX DIMENSION\n"
    exit 0
fi

while getopts ":h?v:m:" flag; do
    case "${flag}" in
        h|\?)
            printf "Usage: -v VECTOR DIMENSION -m MATRIX DIMENSION\n"
            exit 0
            ;;
        v)
            vec_size=${OPTARG}
            ;;
        m)
            mat_size=${OPTARG}
            ;;
    esac
done

# generate typedefs

for ((i=2; i<=vec_size; i++)); do
    printf "typedef struct {\n    float val[$i];\n} vec$i;\n\n"
done

for ((i=2; i<=mat_size; i++)); do
    printf "typedef struct {\n    float val[$((i*i))];\n} mat$i;\n\n"
done

# generate dup_* style functions

for ((i=2; i<=vec_size; i++)); do
    printf "void dup_vec$i(vec$i *src, vec$i *dst)\n{\n"
    printf "    memcpy(dst->val, src->val, sizeof(float)*$i);\n"
    printf "}\n\n"
done

for ((i=2; i<=mat_size; i++)); do
    printf "void dup_mat$i(mat$i *src, mat$i *dst)\n{\n"
    printf "    memcpy(dst->val, src->val, sizeof(float)*$((i*i)));\n"
    printf "}\n\n"
done

# generate scale_* functions

for ((i=2; i<=vec_size; i++)); do
    printf "void scale_vec$i(vec$i *v, float s)\n{\n"
    for ((j=0; j<i; j++)); do
        printf "    v->val[$j] *= s;\n"
    done
    printf "}\n\n"
done

for ((i=2; i<=mat_size; i++)); do
    printf "void scale_mat$i(mat$i *m, float s)\n{\n"
    for ((j=0; j<i*i; j++)); do
        printf "    m->val[$j] *= s;\n"
    done
    printf "}\n\n"
done

# generate addition, subtraction, and Hadamard product functions

mv_names=( add sub had )
mv_operators=( + - '*' )

for x in "${!mv_names[@]}"; do
    name="${mv_names[$x]}"
    op="${mv_operators[$x]}"

    for ((i=2; i<=vec_size; i++)); do
        printf "void ${name}_vec$i(vec$i *a, vec$i *b, vec$i *c)\n{\n"
        for ((j=0; j<i; j++)); do
            printf "    c->val[$j] = a->val[$j] $op b->val[$j];\n"
        done
        printf "}\n\n"
    done

    for ((i=2; i<=mat_size; i++)); do
        printf "void ${name}_mat$i(mat$i *a, mat$i *b, mat$i *c)\n{\n"
        for ((j=0; j<i*i; j++)); do
            printf "    c->val[$j] = a->val[$j] $op b->val[$j];\n"
        done
        printf "}\n\n"
    done
done

# generate vector dot products

for ((i=2; i<=vec_size; i++)); do
    printf "float dot_vec$i(vec$i *a, vec$i *b)\n{\n"
    printf "    return a->val[0] * b->val[0] +\n"
    for ((j=1; j<i; j++)); do
        printf "           a->val[$j] * b->val[$j]"
        if [[ $j == $((i-1)) ]]; then
            printf ";\n"
        else
            printf " +\n"
        fi
    done
    printf "}\n\n"
done

# generate matrix product functions

for ((m=2; m<=mat_size; m++)); do
    printf "void dot_mat$m(mat$m *a, mat$m *b, mat$m *c)\n{\n"
    for ((i=0; i<m; i++)); do
        for ((j=0; j<m; j++)); do
            printf "    c->val[%2d] = " $((i*m+j))

            for ((k=0; k<m; k++)); do
                printf "a->val[%2d]*b->val[%2d]" $((i*m+k)) $((k*m+j))

                if [[ $k == $((m-1)) ]]; then
                    printf ";\n"
                else
                    printf " + "
                fi
            done
        done
    done
    printf "}\n\n"

    printf "void dot_mat${m}vec$m(mat$m *m, vec$m *v, vec$m *c)\n{\n"
    for ((i=0; i<m; i++)); do
        printf "    c->val[$i] = "

        for ((k=0; k<m; k++)); do
            printf "m->val[%2d]*v->val[$((k))]" $((i*m+k))

            if [[ $k == $((m-1)) ]]; then
                printf ";\n"
            else
                printf " + "
            fi
        done
    done
    printf "}\n\n"
done

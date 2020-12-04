def vec_x(n)
    "xyzw"[n]
end

def mat_x(row, col)
    "m#{row}#{col}"
end

def generate_vec(size)
    puts "typedef struct {"
    print "\tfloat "
    print size.times.map { |i| vec_x(i) }.join(", ");
    puts ";"
    puts "} vec#{size};"
end

def generate_mat(rows, cols)
    puts "typedef struct {"
    print "\tfloat "
    1.upto(rows) do |i|
        print 1.upto(cols).map { |j| mat_x(i, j) }.join(", ");
        if i == rows
            puts ";"
        else
            print ",\n\t      "
        end
    end
    puts "} mat#{rows}x#{cols};"

    if rows == cols
        puts
        puts "typedef mat#{rows}x#{cols} mat#{rows};"
    end
end

def generate_vec_dup(size)
    puts "void dup_vec#{size}(vec#{size} *src, vec#{size} *dst)"
    puts "{"
    puts "\t*dst = *src;"
    puts "}"
end

def generate_mat_dup(rows, cols)
    dim = "#{rows}x#{cols}"
    puts "void dup_mat#{dim}(mat#{dim} *src, mat#{dim} *dst)"
    puts "{"
    puts "\t*dst = *src;"
    puts "}"
end

def generate_vec_init(size)
    print "void init_vec#{size}(vec#{size} *v, "
    print size.times.map { |i| "float #{vec_x(i)}" }.join(", ")
    puts ")\n{"
    size.times do |i|
        puts "\tv->#{vec_x(i)} = #{vec_x(i)};"
    end
    puts "}"
end

def generate_mat_init(rows, cols)
    print "void init_mat#{rows}x#{cols}(mat#{rows}x#{cols} *m, "
    print 1.upto(cols).map { |i| "vec#{rows} *col#{i}" }.join(", ")
    puts ")\n{"
    1.upto(rows) do |i|
        1.upto(cols) do |j|
            puts "\tm->#{mat_x(i, j)} = col#{j}->#{vec_x(i-1)};"
        end
    end
    puts "}"
end

def generate_vec_elementwise(size, name, op)
    puts "void #{name}_vec#{size}(vec#{size} *a, vec#{size} *b, vec#{size} *c)"
    puts "{"
    size.times do |i|
        puts "\tc->#{vec_x(i)} = a->#{vec_x(i)} #{op} b->#{vec_x(i)};"
    end
    puts "}"
end

def generate_mat_elementwise(rows, cols, name, op)
    dim = "#{rows}x#{cols}"
    puts "void #{name}_mat#{dim}(mat#{dim} *a, mat#{dim} *b, mat#{dim} *c)"
    puts "{"
    1.upto(rows) do |i|
        1.upto(cols) do |j|
            idx = mat_x(i, j)
            puts "\tc->#{idx} = a->#{idx} #{op} b->#{idx};"
        end
    end
    puts "}"
end

def generate_vec_scale(size)
    puts "void scale_vec#{size}(vec#{size} *v, float s)"
    puts "{"
    size.times do |i|
        puts "\tv->#{vec_x(i)} *= s;"
    end
    puts "}"
end

def generate_mat_scale(rows, cols)
    puts "void scale_mat#{rows}x#{cols}(mat#{rows}x#{cols} *m, float s)"
    puts "{"
    1.upto(rows) do |i|
        1.upto(cols) do |j|
            puts "\tm->#{mat_x(i, j)} *= s;"
        end
    end
    puts "}"
end

def generate_vec_dot(size)
    puts "float dot_vec#{size}(vec#{size} *a, vec#{size} *b)"
    puts "{"
    print "\treturn "
    print size.times.map { |i| "a->#{vec_x(i)}*b->#{vec_x(i)}" }.join(" + ");
    puts ";"
    puts "}"
end

def generate_mat_vec_mult(rows, cols)
    puts "void mult_mat#{rows}x#{cols}_vec#{cols}(mat#{rows}x#{cols} *m, vec#{cols} *v, vec#{rows} *dst)"
    puts "{"
    rows.times do |i|
        print "\tdst->#{vec_x(i)} = "
        print cols.times.map { |j| "m->#{mat_x(i+1, j+1)}*v->#{vec_x(j)}" }.join(" + ");
        puts ";"
    end
    puts "}"
end

def generate_mat_mult(m, n, p)
    puts "void mult_mat#{m}x#{n}_#{n}x#{p}(mat#{m}x#{n} *a, mat#{n}x#{p} *b, mat#{m}x#{p} *dst)"
    puts "{"
    print "\tfloat "
    1.upto(m) do |i|
        print 1.upto(n).map { |j| "a#{i}#{j} = a->#{mat_x(i, j)}" }.join(", ");
        print ",\n\t      "
    end
    1.upto(n) do |i|
        print 1.upto(p).map { |j| "b#{i}#{j} = b->#{mat_x(i, j)}" }.join(", ");
        if i == n
            puts ";"
        else
            print ",\n\t      "
        end
    end
    puts

    1.upto(m) do |i|
        1.upto(p) do |j|
            print "\tdst->#{mat_x(i,j)} = "
            print 1.upto(n).map { |k| "a#{i}#{k}*b#{k}#{j}" }.join(" + ")
            puts ";"
        end
    end

    puts "}"
end

def generate_all
    vec_sizes = 2..4
    mat_sizes = 2..4

    vec_sizes.each { |size| generate_vec(size); puts }
    mat_sizes.each do |rows|
        mat_sizes.each { |cols| generate_mat(rows, cols); puts }
    end

    vec_sizes.each { |size| generate_vec_init(size); puts }
    mat_sizes.each do |rows|
        mat_sizes.each { |cols| generate_mat_init(rows, cols); puts }
    end

    vec_sizes.each { |size| generate_vec_dup(size); puts }
    mat_sizes.each do |rows|
        mat_sizes.each { |cols| generate_mat_dup(rows, cols); puts }
    end

    vec_sizes.each { |size| generate_vec_scale(size); puts }
    mat_sizes.each do |rows|
        mat_sizes.each { |cols| generate_mat_scale(rows, cols); puts }
    end

    vec_sizes.each { |size| generate_vec_elementwise(size, "add", "+"); puts }
    mat_sizes.each do |rows|
        mat_sizes.each { |cols| generate_mat_elementwise(rows, cols, "add", "+"); puts }
    end

    vec_sizes.each { |size| generate_vec_elementwise(size, "sub", "-"); puts }
    mat_sizes.each do |rows|
        mat_sizes.each { |cols| generate_mat_elementwise(rows, cols, "sub", "-"); puts }
    end

    vec_sizes.each { |size| generate_vec_dot(size); puts }

    mat_sizes.each do |rows|
        mat_sizes.each do |cols|
            generate_mat_vec_mult(rows, cols)
            puts
        end
    end

    mat_sizes.each do |m|
        mat_sizes.each do |n|
            vec_sizes.to_a.union(mat_sizes.to_a).each do |p|
                generate_mat_mult(m, n, p);
                puts
            end
        end
    end
end

generate_all

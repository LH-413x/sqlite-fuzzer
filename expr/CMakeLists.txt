include_directories(
        #${PROJECT_SOURCE_DIR}/include/expr
        ${PROJECT_SOURCE_DIR}/include
        )
set(srcs    cast_expr_as_generator.cpp
            expr_generator.cpp
            literal_value_generator.cpp
            stc_generator.cpp
        )
add_library(generator ${srcs})
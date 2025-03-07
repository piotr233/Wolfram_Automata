cmake_minimum_required(VERSION 3.20)
project(Wolfram_Automata)

set(CMAKE_CXX_STANDARD 14)

set(automata_dir Automata/wolfram_automata.h Automata/wolfram_automata.cpp
        )


set(sfml_dir
        sfml_window/window.h sfml_window/window.cpp
        sfml_window/coord.h sfml_window/coord.cpp
        sfml_window/slicer.h sfml_window/slicer.cpp
        sfml_window/image.h sfml_window/image.cpp
       )

add_executable(Wolfram_Automata WA_main.cpp
        ${automata_dir}
        ${sfml_dir}
        )
add_executable(animation wolfram_animation.cpp
        ${automata_dir}
        ${sfml_dir}
        )
add_executable(root wolfram_root.cpp
        ${automata_dir}
        ${sfml_dir}
        )

add_executable(benchmarks Benchmarks/benchmarks.cpp
        ${automata_dir}
        )

add_executable(wng WNG/kinda_random_number_generator.cpp
        ${automata_dir}
        )
add_executable(final wolfram_1d_automata_console.cpp)
add_subdirectory(sfml)

set(executables Wolfram_Automata animation root)

foreach(executable IN LISTS executables)
    target_include_directories(${executable}
            PUBLIC ${PROJECT_SOURCE_DIR}/sfml/include)
endforeach()

foreach(executable IN LISTS executables)
    target_link_directories(${executable}
            PUBLIC ${PROJECT_SOURCE_DIR}/sfml/src)
endforeach()

foreach(executable IN LISTS executables)
    target_link_libraries(${executable}
            sfml-graphics
            sfml-system
            sfml-window)
endforeach()

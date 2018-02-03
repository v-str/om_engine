macro (add_c_compiler_flags)
    foreach (flag ${ARGV})
        set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${flag}")
    endforeach ()
endmacro ()

macro (add_cxx_compiler_flags)
    foreach (flag ${ARGV})
        set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${flag}")
    endforeach ()
endmacro ()

macro (add_compiler_flags)
    add_c_compiler_flags (${ARGV})
    add_cxx_compiler_flags (${ARGV})
endmacro ()

macro (add_linker_flags)
    foreach (flag ${ARGV})
        set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${flag}")
    endforeach ()
endmacro ()


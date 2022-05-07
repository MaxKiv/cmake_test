file(REMOVE_RECURSE
  "liblibcollatz.a"
  "liblibcollatz.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/libcollatz.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()

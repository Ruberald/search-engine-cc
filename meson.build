project('search-engine-cc', 'CPP', default_options : ['cpp_std=c++20'])

sources = files(
  'src/main.cpp',
  'src/lexer.cpp',
  'src/model.cpp',
  'src/engine.cpp'
  )
incdir = include_directories('headers')

executable('search-engine-cc', sources, include_directories: incdir, override_options : ['cpp_std=c++20'])


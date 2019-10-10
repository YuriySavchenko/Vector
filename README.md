# Vector

```
Simple implementation for Vector
```

### Requirements

You need to install cxxtest, for this follow command below:
```
  sudo apt-get install cxxtest
```
### Bug

*Exists one problem with memory deallocation for std::string which have been produced by initializer_list.*

### Answer

_"First of all: relax, it's probably not a bug, but a feature." © Valgrind.org_

_**Link to documentation:**_ http://valgrind.org/docs/manual/faq.html#faq.reports

_**Link to libstdc++ documentation:**_ https://gcc.gnu.org/onlinedocs/libstdc++/faq.html#faq.memory_leaks

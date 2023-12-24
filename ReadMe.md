## use class

the "class" structure can not be correctly recognized as “type_decl” node, instead recognized as' unknown'.

> file "use_class\\.graphml\\export.xml"
>
> - line 2642, node id 222, class Logger, incorrectly
> - line 4614, node id 392, class util_timer, incorrectly

## use struct

changing the keyword "class" to "struct", joern-parse can run correctly, but the "enum" inside the "struct" cannot be correctly parsed, but the declaration of the function in the ".h" file was incorrectly parsed

> file "use_struct\\.graphml\\export.xml"
>
> - line 1893, node id 153, struct Logger, correct
> - line 1934, node id 154, enum LogLevel, incorrectly
> - line 1954, node id 155, public: static Logger* getInstancePtr(), incorrectly
> - … the declaration of the function
> - line 5636, node id 486, struct util_timer, correct

## no header file

cancel the h file and use the cpp file instead, joern-parse can run all correctly, the "class" "enum" or the function\member in the class.

> file "no_header\\.graphml\\export.xml"
>
> - line 2642, node id 222, class Logger, correct
> - line 2710, node id 223, enum LogLevel, correct
> - line 4614, node id 392, class util_timer, correct
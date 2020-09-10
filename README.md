Code Documentation                     {#mainpage}
=============================================

Commit, Push and Sync Rules
---------------------------
- Don't mix reasons when you commit a change.
- Each modification should be prefixed by the name of the (sub)project.
- Modifications concerning the tree structure, the project settings, etc. should be tagged using
[project] prefix.
- Modifications concerning the addition of a feature should be tagged using [feature] prefix.
- Modifications concerning bugfixes should be tagged using [bugfix] prefix.

Code Standards & Convention
---------------------------------------------
### Global Documentation Guidelines
- Each file must fully documented, including: filename, author, date, version, brief and detailed
descriptions. This header is specified before any line of code.
- Each element should be fully documented at least with a brief and detailed description.
- The size of each line should not exceed more than 99 characters.

### Packages and folders organization
- Each subfolder corresponds to a package, associated to a namespace. Packages and namespaces have 
the same name than the folder they represent.
- Each folder should have a file named `DIRECTORY.md` which describes the tree of this directory.
This file should contains at least a brief and detailed descriptions of each subdirectory.

### Files and Directory names and Extensions
- Filenames and folder names are in lowercase. Names of folders should contain only alphanumeric 
symbols. Words in filename are seperated by `_`.
- Inclusions and references of files should use relative path if it concerns files belonging to the 
project; absolute path, otherwise.

### C++ Specific Rules

#### Extensions
- Header extension: *.hpp
- Source extension: *.cpp
- Template extension: *.tpp

#### Sections
- Headers and sources files are divided into preprocessors directives and code sections.
  Each section begins with a header:   
  ```cpp
  /*
  =================================================================================================
      Section name
  =================================================================================================
  */
  ```
- There is no blank line between the section header and the first line of code (except if
this line is a comment). There is a blank line before the beginning of a section header.

#### Regions
- Use the `#pragma region` directive to split the files into multiples subcategories. There
is blank line before and after the beginning of a region, before and after the end of a region.

### Preprocessor Macros
- Ident rule: Preprocessor instructions should be formatted using block indent rules. Exemple:
  ```cpp
  #define MACRO_1
  #if instruction
      #define MACRO_2
  #endif
  ```
- Regular code inside a preprocessor block is indented according the regular block they belong to.

#### Comments
- Leave a space between `//` or `/* */` and the comment.
- Doxygen blocks begins with `/**` and ends with `*/`, and star-aligned. Use the 
  `\command` version.
    \verbatim
    /**
     * \brief This is a doxygen block.
     */
    \endverbatim

#### Block Convention
- First line: optional keyword + optional identifier + space + opening symbol.
- Content is indented.
- Last line: closing symbol unidented + optional semi-colon + optional comment.

#### Namespaces
- A namespace corresponds to a directory.
- Namespace names are in lowercase.
- Create a specific header file (namespace header) to declare the namespace. This file should:
 - Be place at the same level that the directory which corresponds to the namespace.
 - Document the namespace (brief and detailed description).
 - Predeclare or Declare the elements of the namespace.
 - Include the header files declaring the elements belonging to this namespace.
- Use nested namespace declaration in namespace headers.
- Namespace documentation is done before the declaration of the namespace.
- Namespace declaration follow block convention. Example:
  ```cpp
  namespace mynamespace {
      ... content ...
  }; // namespace mynamespace
  ```

#### Variables naming
- Local variables are named using lowercases symbols only, and each word is separated with `_`.
- Global variables ends with `_`.
- Constant variables begins with an uppercase.

#### Enum & Define values
- Enum values and define values are full upercase.

#### Functions
- Function names follow the local variable naming convention.
- Parameter names follow the local variable naming convention.
- Declaration and Predeclaration of function follow the following convention:
 - (optional) First line: attributes and declarator specifiers
 - Second line: type specifiers
 - Third line: Identifier following the block convention.
- Parameters in Declaration and Predeclaration are unnamed. Example:
  ```cpp
  static
  const int
  function (
      int,
      char * [] 
  );
  ```
- Body in function definitions follows block convention. Example:
  ```cpp
  const int
  function (
      ... params ...
  ) {
      ... content ...
  }
  ```

#### Class, Interface, Structure, Type
- Each word in type identifiers begin with an uppercase, and contains no special symbols.
- Classes, interfaces and structures follow block convention. Except if there is inheritance, 
  the colon symbol is placed after the identifier, with one base ancestor per line (idented). 
  Example:
  ```cpp
  class MaClass3 : 
      public MaClass1,
      public MaClass2 {
      ... content ...
  }; // class MaClass3
  ```
- Each word of an instance member begins with an uppercase except the first word. There is only
alphanumeric symbols.
- Public instance members begin with `_`.
- Protected/Private instance members begin with `m_`.
- Static attributes follow global variable naming convention.
- Instance methods follows instance member naming convention.
- Static functions follows function naming convention.
- Access protection should be in this order: private, protected, public.
- Initializer-list follow the block convention.

Changelog
---------
Code Documentation                     {#mainpage}
===================================================================================================

Dependencies and Installation
---------------------------------------------------------------------------------------------------
The following libraries are needed to build the workspace:
- Qt 5.14
- ROS Melodic
- Gazebo 11.0
- Boost 1.66
- Python 3

Build the Common Library, then the RobotAPI, the ROSProxy, and the MissionPlanner. Launch ros and
gazebo and then run the Mission Planner. And enjoy !

Commit, Push and Sync Rules
---------------------------------------------------------------------------------------------------
- Don't mix reasons when you commit a change.
- Each modification should be prefixed by the name of the (sub)project.
- Modifications concerning the tree structure, the project settings, etc. should be tagged using
[project] prefix.
- Modifications concerning the addition of a feature should be tagged using [feature] prefix.
- Modifications concerning bugfixes should be tagged using [bugfix] prefix.

Code Standards & Convention
---------------------------------------------------------------------------------------------------
### Definitions and Lexicon
- Workspace : Space in which all the subprojects live.
- Project : An subspace of a workspace from which an artifact can be produced.
- Package : The source of an artifact, i.e. there is one package per artifact.
- Namespace : A functional/semantical set of pieces of source code.

### Global Documentation Guidelines
- Each file must fully documented, including: filename, author, date, version, brief and detailed
descriptions. This header is specified before any line of code.
- Each element should be fully documented at least with a brief and detailed description.
- The length of each line should not exceed more than 99 characters.

### Folders tree and organization
- Each folder should have a file named `DIRECTORY.md` which describes the tree of this directory.
This file should contains at least a brief and detailed descriptions of each subdirectory.
- Each subfolder corresponds to a packae or a namespace. Packages and namespaces have 
the same name than the folder they represent.

### Files and Directory names and Extensions
- Filenames and folder names are in lowercase. Names of folders should contain only alphanumeric 
symbols. Words in filename are seperated by `_`.
- Inclusions and references of files should use relative path if it concerns files belonging to the 
same project; absolute path, otherwise.
### C++ Specific Rules

#### Extensions
- Header extension: *.hpp
- Source extension: *.cpp
- Template extension: *.tpp

#### Packages
- Each package should have an external header which can be included to interact with the whole
package.

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

#### Headers
*A header file should always declare or define a package a namespace, a class, or a structure.


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

      /**
       * \brief This is a doxygen block.
       */

#### Block Convention
- First line: optional keyword + optional identifier + space + opening symbol.
- Content is indented.
- Last line: closing symbol unidented + optional semi-colon + optional comment.

#### Variables naming
- Local variables are named using lowercases symbols only, and each word is separated with `_`.
- Global variables ends with `_`.
- Constant variables begins with an uppercase.

#### Enum & Define values
- Enum values and define values are full uppercase.
- Each word in a define identifier are separated by `_`.
- Enum values don't contain `_`.

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
- Access protection should be in this order: public, protected, private.
- Initializer-list follow the block convention.
- Defined types (using typedef) must end with _t.
- Pointer types begin with p (exemple: pClass_t, pchar_t...).

Catkin Build
---------------------------------------------------------------------------------------------------
1. Initialize catkin.
```
$(ROS_INSTALL)\$(Platform)\setup.bat
```
2.Initialize the catkin workspace from the subdirectory `project`.
```
cd $(SolutionDir)/project
catkin_init_workspace
```
3. Build the catkin workspace from the root directory using the project `CATKIN_WORKSPACE` or
```
catkin_make --use-ninja --force-cmake 
    --build "$(SolutionDir)project" 
    --source "$(SolutionDir)project" 
    -DCATKIN_DEVEL_PREFIX="$(SolutionDir)" 
    -DCMAKE_PLATFORM=$(PlatformShortName) 
    -DCMAKE_BUILD_TYPE=$(Configuration)
```
or
```
cmake -S project -B project -G Ninja 
    -DCATKIN_DEVEL_PREFIX="$(SolutionDir)" 
    -DCMAKE_PLATFORM=$(PlatformShortName)  
    -DCMAKE_BUILD_TYPE=$(Configuration)
```
4. To build a specific package:
```
catkin_make --use-ninja --force-cmake 
    --only-pkg-with-deps package_name
    --build "$(SolutionDir)project" 
    --source "$(SolutionDir)project" 
    -DCATKIN_DEVEL_PREFIX="$(SolutionDir)" 
    -DCMAKE_PLATFORM=$(PlatformShortName) 
    -DCMAKE_BUILD_TYPE=$(Configuration)
```
5. Clean the CMakeCache.
```
catkin_make -DCATKIN_WHITELIST_PACKAGES=""
```

Changelog
---------
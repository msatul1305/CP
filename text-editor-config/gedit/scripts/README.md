## External Tools (installed by default)

### CPP : 

Build & Run :  
``` bash
#!/bin/sh
g++ -g -std=c++11 -DLUNU $GEDIT_CURRENT_DOCUMENT_NAME -o ${GEDIT_CURRENT_DOCUMENT_NAME%.*} && gnome-terminal -x bash -c "./${GEDIT_CURRENT_DOCUMENT_NAME%.*}; bash"

```
  
Compile Only :  
```bash
#!/bin/sh
g++ -std=c++11 -DLUNU $GEDIT_CURRENT_DOCUMENT_NAME -o ${GEDIT_CURRENT_DOCUMENT_NAME%.*}
```
  
Debug : 
```bash
#!/bin/sh
gnome-terminal -x bash -c "gdb ${GEDIT_CURRENT_DOCUMENT_NAME%.*}; bash"
```
  
  
### C :  
  
Build & Run : 
```bash
gcc -g -std=c11 -DLUNU $GEDIT_CURRENT_DOCUMENT_NAME -o ${GEDIT_CURRENT_DOCUMENT_NAME%.*} && gnome-terminal -x bash -c "./${GEDIT_CURRENT_DOCUMENT_NAME%.*}; bash"
```
  
Compile Only :  
```bash
#!/bin/sh
gcc -std=c11 -DLUNU $GEDIT_CURRENT_DOCUMENT_NAME -o ${GEDIT_CURRENT_DOCUMENT_NAME%.*}
```
  
Debug : 
```bash
#!/bin/sh
gnome-terminal -x bash -c "gdb ${GEDIT_CURRENT_DOCUMENT_NAME%.*}; bash"
```
  
  
### python : 
  
Run :  
```bash
#!/bin/sh
gnome-terminal -x bash -c "python $GEDIT_CURRENT_DOCUMENT_NAME; bash"
```
  
  
### GO :  
  
```bash
#!/bin/sh
go build $GEDIT_CURRENT_DOCUMENT_NAME && gnome-terminal -x bash -c "./${GEDIT_CURRENT_DOCUMENT_NAME%.*}; bash"
```

## Plugins for ease-of-use :
  
[by nymanjens](https://github.com/nymanjens/gedit-intelligent-text-completion)

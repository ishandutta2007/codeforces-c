#include <bits/stdc++.h>
using namespace std;
/*
Coded by 
The most charming girl in the world
@@@@@@@@@@##&|;!!!!!!!!!!||||||||%%%%%$$$$$$$$$$$$%%$$$&&&&&&&&&$$&&&&&&&&&@@@&%||||||$&&&&@&%;'```'`':!||%&@@@@#@&&&&&@@@&&$$$&&@@&$$$&@@@@@@@@@@@@@#@@@@@@@@@@#@@@@@#@@@@@@@@@@##$
@@@@@@@@@####$!;!!!!!!!!!||||||||%%%%%%%%%%%%%%%$$$$&&&&&&&&&&&&&&&&&&&&@@@@@@&%|||||!:'`'!$&&&&&&%:''!|||$&&&@@@@@@&&&&&@@@&$$$&&@&&$&&@@@@@@@@@@@@@@@@@@@@@@@@##@@@@#@@@@@@@@@@#@%
@@@@@@@@@####@|;!!!!!!!!!|||||||%%%%%%%%%%%%%$$$$$$$$$$&&&&&&&&&&&&&&&@@@@@@@@&%|;:'''''``````'!$&&&@@&|:;%$$&&&@@@@@&&&&&@@@&$$$&&@@@@@@@@@@@@@@@@@@@@@@@#@@@@@#@@@@@#@@@@#@@@@##@%
@@@@@@@@####@@&|;!!!!!!!!|||||||%%%%%%%%%%%%%%$$$$$$$$&&&&&&&&&&&$$$&&@@@@@@@@@@&$|;'''''````````'':!$&&&$%%%%$$&@@@@@&&&&&@@@@&&&@@#@@@@@@@@@@@@@@@@@@@@@@@@@@@#@@@@@@@@@@#@@@@#@@%
@@@@@@@#####@@@$!;!!!!!!|||||||%%%$$$$$%%%%%%%%%$$$$$$$&&&&&&&&&$$$$&&@@@@@@@@$%$&@@&&&@&$%;:':;:''`````'|%%%%%%$$&@@@@@&&&&@@#@@@@@@#@@@@@@@@@@@@@@@@#@@@@@@@@@#@@@@@@@@@@@@@@#@@@%
@@@@@@#####@$%%%$$$%%%||%%||||%%%%$%%$$$$$%%%%%%%$$$$&&&&&&&&&$$$$$$&&@@@@@@@&$;'''''':!%&&&&&&@@&%;'```:$&&%%%%%$$$&@@@@&&&&@@@@@@@@@#@@@@@##@@@@@@@@#@@@@@@@@@@@@@@#@@@@@@@@@#@@@%
$&@@@@######&&&&&$%%%%|%|||||||%%%%%$$$$$$$$$$$$$&&&&&&&&&&&&&&&&$$$$&&@@@@@@&$!''''''````````:!|$&&&&&&&$&&&$%%%%$$$&&@@@&&&&&@@@@&@@@@@@@@@#@@@@@@@@#@@@@@&&&@@@@@@@@@@@@@@@#@@@@$
$$$&@######@&&&&&&|!!!!!|||||||%%$$$$$$$$$$$$$$$&&&&&$$&&&&&&&&&&&&$$&&&@@@@@@&%;::''````````'':'``....`;|%$&&&$%%$$$$$&@@@&&&&&@@@@@@@@#@@@@@#@@@@@@@@@@@@@@&&@&&&&&&&&&@@@@@@@@@@$
$$$&@#####@&$$&&@#&|!!!!!|||||||%%%$$$$%%%%%$$$$$$$&&&&&&&&&&&&@@@@@&&&&&&@@@@@@@@@@@&&&&&&&&@@@@&&$$%||||%%%$$&&&$$$$$$$&@@@&&&&&@@@@@@@#@@@@@@@@@@@@@@@@@@@@&&@&&&&&&&&@@@@@@@@@#$
$$&@######@&$&@##@&$|!!!!|||||||%%%%%%%%%%%%%$$$$&&&&&&&&&&&&&&&&&&&&$$&&&&&&@@&|'`````````':::;;;;;;!|%%%%%%%%$&@@&$$$$$$$&@@&&&&&@@@@@@@@@@@@@@@@@@@@#@@@@@@@@@&&&&&&&&&@@@@@@@#@%
$&@######@&&&@##@$$$$|!!!||||||||%%%%%%%%%%%%$$$$&&&&&&&&&&&&&&&&&&&&$&&&&&&&&@@$!:::'':::::::::::::''``.:%%$$$$$$&@@@&$$$$$&@@@&&&&@@@@@@@@@@@@#@@@@@@@@@@#@@@@#@@@@@@&&&@@@@@@@@@%
$&@######@&&@#@&$$$$&$|!!!||||||||%%%%%%%%%$$$$$&&&&&&&&&&&&&&&&&&&$$$&&&&&&&&&&&%;::::::::::::':''':'':::%&$$$$$$$$&&@@&$$$$$&@@@&&&&@@@@@@@@@@@@@@@@@@#@@@@@@@@@@@@@@@@@@@@@@@@@@%
&@#######@@@#@&$$$$$&&$|!!|||||||||%%%%%%$$$$$$$$$&&&&&&&&&&&&&&&$$$$$&&&&&&&&&&&$!''::::'''::;!|%%$&&@@@@&&@@$$%%$$$$&&@&&$$$$&@@@&&&&@@@@@@#@@@@@@@@@@@@@@@@@#@@@@@@@@@@@@@@@@@@@%
############&$$$$$$$&&&$|!!||||||||%%%%%%$$$$$$$$$$$$$$&&&&&$$$$$$$$$$&&&&&&&&&&&&@@@&&&&&&&@@@@@@&&&$$%|!;%@@@@&$$$$$$$$&@@&$$$$&@@@&&&@@@@@@@@@#@@@@@@#@@#@@@@@@@@@@@@@@@@@@@@@@@$
########@&$$$$$$$$$&&&&&$|!!||||||%%%%%%$$$$$$$$$$$$$$$$$$$$$$$$$$$$$&&@@&&&&&&&&&&&&&&$$$$$$$$$$&&&$$%!;:::|$&@@@@&$$$$$$$&@@&$$$&@@@&&&@@@@@@@@##@@@@@@@@@@@@#@@@@@@@@@@@@@@@@@@@$
########@$%%%$$$$$$&&&&&&&%!||||%%%$$$%%%%%%%%%%%%%%%%%%%%%%%$$$$$&&&&&&&&&&@@@&&&&&&&&&&&&$$$$$$$$$$$$$&&%!!$$$$&@@@@&$$$$$$&@@@&&&&@@@&&@@@@@@@##@@@@@#@@@@@@@@@@@@@@@@@@@@@@@@@@%
#######@&$$$$$$$$$$$$&$|!||%%%%||%%%%%%%%%%%%%%%%%$$$$$$&$$$$$&&&&&&&&@@@@&&&&&&&&&&&&&&&&&&&$$&&$$$$$$$$$&&&$&@&$$$&@@@&$$$$$$&@@@@&&@@@@&@@@@@@###@@@@@@@@@@@@@@@@@@@@@@@@#@@@@#@%
#######@$$$$$$%$$$$$$$&&$||||%%%%%%$$$$$$$$$$$$$$$$$$$$$$$&&&&&&&&&&@@&&&&&&&&&&&&$$$$$$&&&&$$$$$$$$$$$$$$$$$$&@@@@&$$$&@@@&$$$$&&&@@@&@@@@&&@@@@@###@@@@#@@@@@#@@@@@@@@@@@#@@@@#@@$
#######&$$$$$$$$$$&$$$$$&&&&&$%||%%%%%%$$$$$$$$$$$$$$$$$&&&&&&&&&&&@&&&&&&&&&&&&$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$&&@@@&$$$&@@@&$$&&&@@@@@@#@@@@@@@@##@@@@#@@@@@@@@@@@@@#@@@@@@##@##$
######@$$$$$$$$$$$$$$$$$$&&&&&&$||%%%%%%%$$$$$$$$$$$$$&&&&&&&&&@@&&&&&&&&&&&&&&$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$&@@@@@&&$&&@@@&&&&&@@@@@##@@@@@@@##@@@###@@@@@@@@@@@@@@#@@@#@#@@%
######&$$$$$$$$$$$$$$$$$&&&&&&&&$%|%%%%%%%$$$$$$$$$$&&&&&&&&&&@&&@@&&&&&&&&&&$$$$$$$$$$$$$$$$$$$$$$$&$$$$$$$$$$$$$$$$&@@@@@@&&&&&@@@&&&&@@@@@#@@@@@###@@@##@@@@@@@@@@@@@@#@@@####@#$
#####@$$$$$$$$$$$$$$$$$$$&&&&&&&&&%%%%%%%%%$$$$$$$$&&&&&&&&&&&&&&&&&&&&&&&&$$$$$$$$$$$$$$$$$$$$$$$$$$&$$$$$$$$$$$$$$$$$&&&@@@@@&&&&@@@@@@@@@@@@#@@@@###@@@$%%%%%%%%%%%%%$&@@#######$
#####@&$%$$$$$$$$$$$$$$$$$$&&&&&&&&$%%%%%%%%%%$$$$&&&&&&&&&&&&&&&&$$$$$$$$$$$$$$$$$$$$$$$$$$%$$$$$$$$$%%$$$$$$$$%%$$$$$%&@&&&&@@@@@&&@@@@@&&@@@@#@@@@###@&%%%%%%%%%%%%%%%%%&@##@##@%
####@@@@&$$$$$$$$$$$$$$$$$$&&&&&&&&&&%%%%%%%%%%$$&@&&&&$&&&$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$||$$$$$$$$%%$$$$$|%$$$$$$$%%$&@@@&&&@@@@@@@@@@@@&@@@@@@@@##@&%%%%%%%%%%%%%%%%%%%$@@@@@%
####@@@@@@&$%$$$$$$$$$$$$$$$$$&&&&&&&&$%%%%%%%$&&&&&$$$$$$&$$$$$$$$$$$$$$$$$$$$$$$%%$$$%%%%|!|||$$$$%!|%%%$$&$$$$$$$$$$%%%$&@#@@@@&&@@@@@@@@@@@@@@##@@@@#@@@&$$%%%%%%%%|%%%%%|$@@@@$
###@@@@@@@@$$$%$$$$$$$$$$$$$&&&&&&&&&&&&%%%%%&&&&&$%%%$$&&&$$$$$$$$$%%%$$|%$$$%%%$%%|%%!;!||!!||%$$$$$$$%%$&$$&&$$$$$$$$$$%%$@@#@@@@@@&&@@@@@@@@#@@###@@@########@@$%%%%%%%|%%$&@##$
##@@@@@@@@@&$$$&$$$$$$$$$$$$$$$&&&&&&&&&&&%%%$&%|%%%%%$%%$$%%%%%%$$$%%%$$||%%%$$$$$%%%%%$$$$$%!!|%&&$$$$%|$$$$$$&$$$$$$$$$$$%$$&@@@@@@@@@@@@@@@##@@@@##@@####@@#######&%%%%%%%$@###$
#@@@@@@@@@@&&$$&$$$$$$$$$$$$$$$&&&&&&$||%%%$$%!;!;!|%%%%$%!||||%%%$$$||%$%%%%%%$$$$%$$%%%%$%$$$$||$&&$$&%|%$$$$$$$&$%%$%|%$$$$%$%$@@@@@@##@@@@@@@@@@########@##@@@######&$$&@@@@@##$
@$$&@@@@@@@&&$$$$$$$$$$$$$$$$$$&&&$&&&&$$&$$%!|%%%%%%%%%%||%%%%%%%%$$||%$$$$%%%%$$$%%$$%%%%%%%$$%|%&&$$&$%%$$$$$$$&&$%%&&&&$$$$$$$||$@@@@@@@@@@@@@@@@@@@####@@@@##@@@#@@@@@@@@@@@@@%
&$%%$$&&&$$$$$$$$$$$$$$$$$$$$$$$$$$&&&&&&&&|!|%%%%|%%%%%%$%%%%||||%$$%|%$&&$%%%%$$$$%$$%%%%$$$$$%|$&&&$&$$$&$&$$$$&&&$%$&&&$$&&&&&$%!!|$&@@@@@@@@@@@@@@@@###@@@@@@@@@@@@@@@@@@@@@@@%
$$%$$$$$$$$$$$$$$$$$$$$$$$$$$$$&&&$&&&&&&$|!|||%%|%%%%%%$$%%%%||||%$$%%%$&&$%%%$$&&&$$$$$$$$$$$$$%%&&&&&$$&&$&$$&&&&&&&&&&&&&&&&&&&&$|!!!!$&@@@@@@@@@@@#####@######@##@@&@@@@@@@@@@$
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$&&&&&&$|!|||%$%%%%%%%$$$$%%%||||%$$%%%$&&$$%%$&&&&&$$$$$$$$$$$$%%&&&&&$$&&$&$$&&&&&&&&&&&&&&&&&&&&&&%!!!!|&&&@@@@@@#########@########@@##########$
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$&&&&&$&$%|!||%$$%%$%%%%$$$$$%%|||||$$$&$$&$$$%$&&&&&&$$$$$%$$$$$$%$&&&&&&&&&&&$$&&&&&&&&&&&&&&@@&&&&&@@$|!$@&||||%&@#@@####@########@@@@@@@#@&&@@##$
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$&&&$$&$%|!||%$$%%%%%%%$$$%$$%%||||%$&&&&&&$$$$$$&&&&&$%$$$%%$$$$$%$&&&&&&&&$$$$$&&&&&&&&&&&&&&@@@&&@@@@@&@@&|||||||||%&@###############@@@@@@##@@@@%
%$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$&$&&$$$$%!!|%$$$%%%%%%$$$$%$$$%||||$&&$$&&$$$$$$$&&&$&$%%$%%%%%%$$%$$$&&&&&$$$$$$&&&&&&$&&&&&&&&&&&&&&&@@@@&||||||||||||$@#####@@@########@@@@@###@@$
%%%%%%%%$$$$$$$$$$$$$$$$$$$$$$$$$&&%%&%!!||%$$%%$$%%$$$$%%$$%%|!|%&&$%%&&$%%%%$$$&$|%$||$%%%%%%$$$$$$&&&&$$$$$$&&&&&&$$$&&&&&&&&&&@@&&&@@@&&%|||||||||%&@@##@$$@@@@########@@@@@@##$
;:''':;!|%%$$$$$$$$$$$$$$&&&&&&&&%%&&$!!|%%%%%%%$$$$$$$%%%$%%%|||$$&%!%&$%%%%|%%%&%!|$||%%%%%%%$$$$%%$&&$$$$$$$&&&&&&$$$$&&&&&&&&&&&&&&@@@@&&%|||||||%@@@@#@%|&#$||||%&@@@@@@@@@@@@$
.....  .`;|%%$$$$$$$$$$$&&&&&&$%%$&&$!;|%%|||%%$$&&&&$$%%$$%%%%%%%&%!;|$$%||||%%%$|;!%||$%$$$$$%%%%||$&$%%%$$$$&&&&&&$$$$&&&&&&&&&&&&&@@@@@@&&%|||||$@@@##&%|%@@%||||||||||&@@@@@@@%
........  `;|%$$$&&&&&&&&&&&$%$&&&&$|!|%%|!!|||$&$&&&$$%%%%%||||%$$|;;|%%|||||%$&&$|!|!!%%%%%%|!!|%!%$$%||%$&$&&&&&&&$$$$&&&&&&&&&&&&@@@@@@@@&&%|||$@@@##@$||$#&|||||||||||&#$|||||!
...    ..  `;|%$$$$&&&&&&$%$$&&&&&&||%%$||!!||$&$$$$$$%%%%%%||||%$%!:!!!%%$$$%%%%|!;;;;;!!!!!;;;||!%&%|%%%$&&$&&&&&&&$$$$&&&&&&&&&&&@@@@@@@@@&&$||$@##@@@%||%&@$||||||||||%&@$|||||!
       ..  .'!|%$$&&&&&&&&&&&&&&&&||$$&%||!||%&&$$$$$$%%$%||||||%|!;:;;;|%|!!!!!|!|$$&&&&$$$%!!!!;|&&$%%%$&$$$$%||&@&$$$$&&&&&&&&&@@@@@@@@@@@@&$|%@@@@#@%|||$@&%||||||||||%@@%|||||!
       ... .';|%$$&&&&&&&&&&&&&&&%%&$&&%|||||%&&$$$$$$%%$%%%||||%!;:::::::'':;!|%%%%$&@&&$%|!|%|;!$&$%|%%$$$$&$|!|$@@&$$$&@@@@@@@@@@@@@@@@@@@@&$$@@@#@&%|||%&#$|||||||||||$@&%|||||!
    ....   .:!|%$$&&&&&&&&&&&&&&$$&&&&$|||||%$@&$$&$$&&&$%|%%%%|;::''''''````'!!!;'`'%@&%|!::!;;!$$||%%%$&$$$$|!!|%&@@&&&&@@@@@@@@@@@@@@@@@@@@&&@@@@#@%||||$@@$|||||||||||$#&||||||!
     ..   .';!|%$$$&&&&&&&&&&&&$$&&&&&$$%||%%&@&$$&$$$$%|!;;;;:::'`````````````````';;:;!;'::::;%$|||!!|$$$%$%||||$@@@&&&@@@@@@@@@@@@@@@@@&&@&&&&&&@@@$%%||&#&%||||||||||%&#$||||||!
        .`:!!!|$$&&&&&&&&&&&&&&&&&&&&&&&$%$$$&@&&$&&$$|!|%$$$$%|;''``````````````':;!!!;::''':;!$%|$$%%$$$$$$%!!%&@@@@@@@@@@@@@@@@@@@@@@@@&&&&@&$$&@@@@@@@@@#&%||||||||||%@@$||||||!
;:''`'':;!!!!|%$$&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&$&&&&&$|!%%%%$&$$|;'``````````````''''''''::::;|$&$$$%%$$%%$$$&@@@@@@@@@@@@@@@@@@@@@@@@@@@&&&@&$$$&&&@@@@@@@@@@@@@@&$%|||$@@$||||||!
|!;;;!!!!!!|%$$$&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&%!:;|!||!!:'''``````````````''''''''':;;|$$$$$%%$%$$$&&&&&@@@@@@@@@@@@@@@@@@@@@@@@&&&@&$$$&&&&&@@@@@##@@@@@&&@@@@@@#@&%|||||!
%|!!!!!!||%$$$&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@&&&&&&$$$!';;;:'```''`````````````````'''''';;:|$$$$$$$$%$$$&@&&&&@@@#@@@@@@@@@@@@@@@@@@@&&@&$$$$$$$&&&@@@@##@%;''|&@@@@@@@#@@@@@@@%
&$%%%%%%$$$$&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@&&&@&&&$$$%;``'''``':'``````````````````'''':::;|$$$$$$$%$$$$&&&&&&@@@##@@@@@@@@@@@@@@@@@@&@&$$$&&&$$$&&&@@@@|:''':%@@@@@@@#@@@@@@@@%
@@&$$$$$&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@&&@@&&&$$$$%:``````';:'```...`````````````'''':;|$$$$$$%%$$$$&&&&&&&@@##@@#######@@#@@@@@@#@&$$&&&&&$%$$&&@@%:'::'!&@@@@&@@@@@@@@@@@%
##@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@&&&&&&&$$%:``````':;:```..``````````````''':;|$$$$$$%%$$$&&&&&&&@@@####################@&$$&&$$$$$$$|;|&$!''':;$&&&&&&@@@@@@@@@@@%
##@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&$&@&$&&&$&&&&&%'``````.``````....```````````'`'';|$&$$$%$$$$$$&&&&&@@@@@##################@$$$&&$$$$$|:':;%&$;''''|&&&&&&&&@@@@@@@@@@%
##@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&$%$&@@$$$$$&&&&&@@!````````.......````````````''`'':!%$&&&$$&&&&&&&&&&@@@#@@##############@@&$$$$&$$$$$$|:''|&&|''''!$&&&&&&@@@@@@@@@@@@%
##@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&|;%&$&@$$$$$$&&&&&@@&;..``..........````````````''``'';%$&&&&&&&&&&&&&&@@@@@##@############@@@$$$$&$!|$$$$!:':%@%:``':%&&@@@@@@@@@@@@@@@@@%
##@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&$!!$&&$&&$|!|%$$$&&&@@@@$:.........``'''``':;:'`````````':!%$&&&&&&&@&&&&&@@@@@@@#@@#########@@@&$$$%!!$$$$$%;'';$&!``':%@@@@@@@@@@@@@@@@@@@&%
##@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&|;%&&&&$%%$%!|%%$$$$&&@@@@@$;`.....`...````````````````````';|$&&&&&&&&@@@&&&@###@@@@#@&&##@@@@@&$$$$&&$$$$$$|'```!&%;|&&&&&@@@@@@@@@@@@@@@&&&&%
###&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&%:|&&&&&$$||$&$|%%%$$&&&@@@@@@@@$;`........``'::'`...```'``````:|$$$&@@&$&@@@@@@&@#@@####@#&&#@$|%&$$%%&&$$$$%!'`.`:!$@@&&&&@@@@@@@@@@@@@@&&&&&&&&%
###@&&&&&&&&&&&&&&&&&&&&&&&&&&|:!&&&&&&$$%||$&&$%%%$$&&&&@@@@@@@@@@&%:`.................`'````:!;;|$$$&&@@&&&&@@@@&&@########@!':|&$$%%$|;:;;!|%%%%||$@@&&&&&&&@&&&&&&&&&&&&&&&&&&&%
###@&&&&&&&&&&&&&&&&&&&&&&$!:|&&&&&&&&$$%|%$&&&$%%%$&&&&&@@@@@@@@@@@@&&$;`..............``'';|!;;;;|%$$$$&@@@&&&@@&&$$&&@@@@##@&%||%%%$!:|%%%%%||%!|$@@@&&&&&&&&$$$$$$&&&&&&&&&&&&&%
###@&&&&&&&&&&&&&&&&&&&|:!$&&&&&&&&&&$%%%%$$&&&$%%$$$$&&@#@@@@@@@@@@@&&&&&&|'...........``:!!;;;;;!!;|$&$%|&@@@&&&&&$!|$$$&@@#@@&%%%%$|'':!%%%%|!|$&&@@&&&&&&&$%%%%$$$$$&&$$$$$$&&&%
###@&&&&&&&&&&&&&&&|:;%&&&&&&&&&&&&$$%%%%$$&&&&$$$$$$$$&@#@@@@@@@@@&&&&&&&&&&&&|'.....`;%%!!!!;;;!!!!;!%$$&$|%@@@@@&&@$;:::!|%$&$%%%$%:'``';!!|||%$&@@@&&&&&&$%%%%%%%$$$$$%%%%$$$$$|
###@&&&&&&&&&$|:;%&&&&&&&&&&&&&&&$$%%$%%$&&&&&&$$$$%$$$&@@@@@@@@@##@&&&&&&&&&&&&&&%|%&&&&&$|;;;;;;;;;;;;!$&$&$|!%&@@@@@@&%;::!$$$$$$%;:```````;||||%$&&$$$$$$%|%%%%%%%$$$%%%%%%%%$%|
###@&&$%|||$&&&&&&&&&&&&&&&&&&$$$$%%$$%$&&&&&&&$$$%%$$&&@@@@@@@@@@@##@&&&&&&&&&&&&&&&&&&&&@%;;;;;;;::;;;;!!$&&$$%!;|$$$&&&$&&&$$$$$%!|$&%:...`.`;|!|||!;!|||||||%%%%%%$%%%||||%%%%%|
&&@@&&&&&&&&&&&&&&&&&&&&&&&$$$$$$%%$$%$&&&&&&&&$%%%%$$&&@@@@@@@@@@@@#@&@@&&&&&&&&&&&&&@###&%;;;;;;::::;;;!!!!|$$$&&%!:;!$&&&@&$$$&@&&&$%$&|``..'%#@@&$%%||||!;:'`';|%%$%%|||||||||||
###@&&&&&&&&&&&&&&&&&&&&$$$$$$$$%%$&&$$&&&&&&&&$%%%%$$&&&@@@@@@@@@@@@@@&&&&@@@@@&&@####$;':!!;;;::::;;;;!;!;::::;%&&&&&$$$&@&$$$@@$$$$$&@@@@$%@#@@##@@&%%||||||||%%%|!'`:!||||||||||
###@&&&&&&&&&&&&&&&&&$$$$$$$$$$$$$$$%%$$$$&&&&@$%%%%$$&&&&&@@@@@@@@@&&&&@@&&&&&&&@@@@|:':;;!!;;:::::::;;!!;:::::::::':::';$$$$$&&$&&&@@@&&@@@@@#######@@##@&%||||||||%%%%|!''!|||||!
###@&&&&&&&&&&&&&&$$$$$$$$$$$&&$$$$$%%$$$$$&&&&&$%%$$$&&&&&$&&&@@@@&&&&&&&&&&&&@@@%:''':;;;;;:::::::::;;;:::::::::::::;;!%$$$$$|:::|$&&$&@@@@@&$&@#####@@@@####@&$%||%%%||||||;:!||!
###@&&&&&&&&&&&$$$$$$$$$$$&&&&&$$&&$%%$$$&&&&&&&&$%$$$$$&&&&&&&@@@#@&&&&&&&&@##$;''''':;;;;;:::::::::;!;:::::::::::::::;%&$$$$|''':;%&%!;:'''':|%$&@@@@#@@&&&@##@&&@@$|%%|||||||!:;|
:;$@@&&&&&&&$$$$$$$$$$$&&&&&&&&&$$&&$$&&&&&&&&&&&$%%$$$&&&&&&&&&&&&@@#######@|:'''''';!!!;::::::;;!!!!;::::::::::::::::|$$$$$!'::;!!%&|;;''''''''''';$&@@#@&&$$&@&&@#@@@#####@$%||;:
''''':|$&$$$$$$$$$$&&&&&&&&&&&&&&$$&$$&&&&&&&&&&&&&$$$$$&&$$&&&&&@@@@@&$%$%|:''''''':;:::::::::::::;;:::::::::::::::::|$$$$$!::;;;;|&%;;:''''''''''''':!$&@@@&$$$$&################$
'''''''''';%$$&&&&&&&&&&&&&&&&&&&&$$$$&&&&&&&&&&&&&&$$$$$&@@@@@###@&&$%;''''''''':::;;:::::::::::;;:::'':::::::::::':|$$$$$!::;:::|&%;;:''''''''''''''```:%&@@&&&$$$&##############$
'''''''''''':':|&&&&&&&&&&&&&&&&&&&&$%$&&&&&&&&&&&&&&$$$$$&@@&@@@&$$%%!:''''''::::::!;::::::::::;;::::::::::::::''':|$$$$$|;;:::;%&|::'''''''''''''`.....``;$@@&&&&$$$&@###########$
;:'''''''''''''':::!$&&&&&&&&&&&&&&&&&%|$&&&&&&&&&&&&&&$$$$&$$$$$$|:!|;':::::::::::;!;::::::::;;:::::::::::::''''':|$$$$$|;::::|&&|::'''''''''''``........`''!&@@&&&&$$$&@#########$
.';;;;;:'''''''''''':::;%&@&&&&&&&&&&&&%$&&$$$$&&&&&&$&@&&&$$$$%!:::!|;::::::::::::!!;::::::!;::::::::::::::''''':|&$$$$|;::::|&%;;:'``''''''''````......````'!$@@&&&&&$$$&@#######$
;;;:`.`:;;;;::'''''''''''':;%@@@&&&&&&&&$$$&&&&&&&&&&@@&!::':'':::::||;::::::::::::!!;:::;!!;;:::::::::::::::''':%&$$$$|;:::;%&|:::'`````````'''```..`...````''!$@@&&&&&&&$$&@#####$
;;;;;;;;;'..';;;;::''''''''''':|@@@@&&&&&&$%$&&&&&&&@@%:::::::::::::!|;:::::''''''';!;:;!!;:::::::::::::::::''':%&$$$%|;:::|&%;;:'''```````'''''``...      ```''!&@&&&&&&&&&&&&@###$
:::;;;;;;;;!;;;'':;;;;:'''''''''':!&@@@&&&&&$$&&&&@@@$;::::::::::::';|:``````````'';!;;;:'''```````````````''''|$$$$%|;::|&$!;;:'````````''::''``....      .``'':%@&&&&&&&&&&&&&&@#$
::::::::;;;;;;;;;;;;:'':;;:''''''''':;%@@@@&&&&$&@@@$;''''''':''`''`:|;````````````:!!:'''``.........``......`!$%%%%|;;|&$!:;'`````````'''::''.     ..    `''``''!$&&@@&&&&&&&&&&&&%
###@%!:::::::;;;;;;;;;;;;;;;;::'''''::::|&@@@&&&&&&%'```.....````''`'||'``````````';;'''``................. .!$%%%%|!%&$!:;:'``'''````'::::''.       ....``''``'''|@&&&@&&&@&&&&&&$|
####@&&&@&|;::::::;;;;;;;;;;;;;;;:'''''''::!&@@@@@%:````......```'```;%;`````````''''``.................   .!$%%%%%$&%;:::''```'''```'::::'`.         ...``'```''';$@&&&@@&&&&&&&&&%
####@&&&&&&&&&$!:::::::;;;;;;;;;;;;;:''''''':|@@@$;````.......``''```'!%;``````''''``.......      ....    .;%%%%%%$%;::'''`````''''`'::::`.             ...`````'''|@&&&&@@&&&&&&&&%
####@&&&&&&&&&&&&&&|;::::::;;;;;;;;;;;;:::'':;;%&;````.........``'````:||:```':''`......                .`:|%%%%%|;::''''``````'''''::::`.               ....```'''!$@&&&&@@&&&&&&&%
####@&&&&&&&&&&&&&&&&&&|::::::::;;;;;;;;;:::::;;'````..........``'`````:||:':''`......                .`'!$%%%%|;:''```````````'''''::;'.                 ......``':%@@&&&&&@&&&&&&%
####@&&&&&&&&&&&&&&&&&&&&&$!:::::::;;;;;;;;;;;;'`````..........`''``````:||:''`.  .                .``!$&$%%%%%;'''`````````````'':::;;`                   .....```'!&@&&&&&&@&&&&&%
####@&&&&&&&&&&&&&&&&&&&&&&&&&|;:::::;;;;;;;;;:``````...........''````':':|%!'.                .``'|$&|;|%|%%%!''````...`````````':::;;`                    .....```'|@&&&&&&&@&&&&%
####@&&&&&&&&&&&&&&&&&&&&&&&&&&&$!::::::;;;;;:``````....``......''``':'''':!|%;..         ..``:|%$|;::;|%||%%!'`````......```''`'':::;:'   .......           ....````:%@&&&&&&@@&&&%
####@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&%;:::::;;:```````....`.   ...`'':''`.  .':!||;````````';|%%|;::::';|%||%%;'```.........```'''''::::;'. ....````........  ......````:%@&&&&&&@@&&%
####@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&|:::::'```````...``.   ..'::'``.   .```':;!||!;;!||!;::::''``';|%||%|;'```..........```'''''::::;:.....``````````...........`````;&&&&&&&@@@&%
*/

void solve(){
	int b,p,f,h,c;
	scanf("%d%d%d%d%d",&b,&p,&f,&h,&c);
	int ans=0;
	if(c>h){
		int x=min(b/2,f);
		ans+=x*c;
		b-=x*2;
		f-=x;
		x=min(b/2,p);
		ans+=x*h;
		b-=x*2;
		h-=x;
	}else{
		int x=min(b/2,p);
		ans+=x*h;
		b-=x*2;
		p-=x;
		x=min(b/2,f);
		ans+=x*c;
		b-=x*2;
		h-=x;
	}
	printf("%d\n",ans);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}
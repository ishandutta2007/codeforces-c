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

int n,b,q;

struct Query{
	int u,q;
	bool operator<(const Query &Q)const{
		return u<Q.u;
	}
}qs[10005];

int main(){
	scanf("%d%d%d",&n,&b,&q);
	for(int i=1;i<=q;i++){
		scanf("%d%d",&qs[i].u,&qs[i].q);
	}
	sort(qs+1,qs+q+1);
	qs[0].u=0;
	qs[q+1].u=b;
	qs[q+1].q=n;
	q++;
	for(int i=1;i<=q;i++){
		if(qs[i].q<qs[i-1].q){
			puts("unfair");
			return 0;
		}
	}
	for(int i=0;i<32;i++){
		int cnt=0;
		for(int j=1;j<=q;j++){
			int xj=qs[j].u-qs[j-1].u;
			int ccnt=0;
			for(int k=0;k<5;k++){
				if((i>>k)&1){
					int bg=(qs[j-1].u-k+5)/5,en=(qs[j].u-k+5)/5;
					ccnt+=(en-bg);
				}
			}
			ccnt=min(ccnt,qs[j].q-qs[j-1].q);
			cnt+=ccnt;
		}
		if(cnt<__builtin_popcount(i)*n/5){
			puts("unfair");
			return 0;
		}
	}
	puts("fair");
	return 0;
}
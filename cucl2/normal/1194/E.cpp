#include <bits/stdc++.h>
using namespace std;
/*
Coded by 
The most beautiful girl in the world
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

struct Bit_ch{
	int dt[10005];
	Bit_ch(){
		for(int i=0;i<10005;i++){
			dt[i]=0;
		}
	}
	void add(int a,int x){
		while(a<10005){
			dt[a]+=x;
			a+=a&-a;
		}
	}
	int sum(int a){
		int ans=0;
		while(a){
			ans+=dt[a];
			a-=a&-a;
		}
		return ans;
	}
};

int n;
vector<pair<pair<int,int>,int> > h;
vector<pair<int,pair<int,int> > > v;

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		pair<int,int> a,b;
		scanf("%d%d%d%d",&a.first,&a.second,&b.first,&b.second);
		a.first+=5001;
		a.second+=5001;
		b.first+=5001;
		b.second+=5001;
		if(a.first==b.first){
			h.emplace_back(make_pair(min(a.second,b.second),max(a.second,b.second)),a.first);
		}else{
			v.emplace_back(a.second,make_pair(min(a.first,b.first),max(a.first,b.first)));
		}
	}
	sort(h.begin(),h.end());
	sort(v.begin(),v.end());
	set<pair<int,int> > c;
	long long ans=0;
	for(auto i:h){
		Bit_ch bit;
		vector<pair<int,int> > tmp;
		for(auto j:c){
			if(j.first>i.first.first){
				tmp.push_back(make_pair(min(j.first,i.first.second),j.second));
			}
		}
		int now=0;
		for(auto j:tmp){
			while(now<v.size()&&v[now].first<=j.first){
				if(v[now].first>=i.first.first&&v[now].second.first<=i.second&&v[now].second.second>=i.second){
					bit.add(v[now].second.first,1);
					bit.add(v[now].second.second+1,-1);
				}
				now++;
			}
			long long xx=bit.sum(j.second);
			ans+=xx*(xx-1)/2;
		}
		c.emplace(i.first.second,i.second);
	}
	printf("%lld\n",ans);
	return 0;
}
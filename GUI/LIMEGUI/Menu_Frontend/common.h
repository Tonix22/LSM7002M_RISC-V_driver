#ifndef COMMON_H
#define COMMON_H

#define TRANSLATE(Param) QApplication::translate("OpcodeGenerator", Param, Q_NULLPTR)
#define PUSH_TO_LIST(Param) <<TRANSLATE(Param)

#endif
/* FUN_80162a6c
 * image   ovl_00a1414 (ovl), base 0x80161cf0
 * address 0x80162a6c  body 0x80162a6c..0x80162c43  size 472 B
 * body sha256 eefc3e123f591e4da86a3df64d53cbdddbce8470d9dd9260887cc60aa9411dff
 * provider record sha256 aeda41e6b375a2d279becf40ade30b3ff5af547f8ea54cd9d9b7cd9a38703431
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80162a6c(int param_1)

{
  short sVar2;
  short sVar3;
  uint uVar1;
  uint uVar4;
  
  uVar4 = *(uint *)(param_1 + 0x28c);
  func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x5f4);
  sVar2 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x270);
  sVar3 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x338);
  if ((((sVar3 == 0) && (uVar4 < 0x5dc)) &&
      (*(undefined4 *)(param_1 + 4) = 0x1050000, *(byte *)(param_1 + 0x2b6) < 10)) &&
     (uVar1 = func_0x80033604(), (uVar1 & 1) != 0)) {
    *(undefined4 *)(param_1 + 4) = 0x1030000;
  }
  if (*(char *)(param_1 + 0x2b6) == '\0') {
    if (DAT_800e139f != '\0') goto LAB_80162c1c;
    if (((sVar3 == 0) && (uVar4 < 3000)) && (0x708 < uVar4)) {
      *(undefined4 *)(param_1 + 4) = 0x1020000;
      if (((*(ushort *)(param_1 + 0x2b8) & 1) != 0) && (uVar1 = func_0x80033604(), (uVar1 & 3) != 0)
         ) {
        *(undefined4 *)(param_1 + 4) = 0x1070000;
      }
      if ((*(ushort *)(param_1 + 0x2b8) & 0x20) != 0) {
        *(undefined4 *)(param_1 + 4) = 0x1070000;
      }
    }
    if ((((sVar2 == 0) && (uVar4 < 0x9c4)) && (0x708 < uVar4)) &&
       (uVar1 = func_0x80033604(), (uVar1 & 3) == 0)) {
      *(undefined4 *)(param_1 + 4) = 0x1070000;
    }
    if ((sVar3 == 0) && (uVar4 < 0x708)) {
      *(undefined4 *)(param_1 + 4) = 0x1030000;
    }
  }
  if (DAT_800e139f == '\0') {
    return;
  }
LAB_80162c1c:
  if (uVar4 < 3000) {
    *(undefined4 *)(param_1 + 4) = 0x1040000;
  }
  return;
}

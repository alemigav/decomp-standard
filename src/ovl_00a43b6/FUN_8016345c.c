/* FUN_8016345c
 * image   ovl_00a43b6 (ovl), base 0x80161cf0
 * address 0x8016345c  body 0x8016345c..0x801635c3  size 360 B
 * body sha256 39fe50c8e3a5b9c441efc2f1c09d7b7fc9f53a3f91151b4f3a042d75459457f8
 * provider record sha256 ce72f3825eaa3549619df86a0d72d9264551e25b98584765fa9d31732759c5ed
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8016345c(int param_1)

{
  short sVar1;
  char cVar2;
  uint uVar3;
  
  if ((*(short *)(param_1 + 0x2c0) == 0) || (*(short *)(param_1 + 0x1f2) < 100)) {
    *(undefined2 *)(param_1 + 0x1aa) = 1;
    *(undefined4 *)(param_1 + 4) = 0x1060000;
    return;
  }
  uVar3 = *(uint *)(param_1 + 0x28c);
  sVar1 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x400);
  if ((DAT_800e139f == '\0') && (10 < *(byte *)(param_1 + 0x1e9))) {
    if (sVar1 != 0) goto LAB_8016358c;
    if (uVar3 < 0x5dc) {
      if ((0 < _DAT_800e1310) && (cVar2 = func_0x80033144(param_1,&DAT_800e1130), cVar2 == '\0')) {
        *(undefined4 *)(param_1 + 4) = 0x1040000;
        *(undefined1 *)(param_1 + 0x2c4) = 0;
      }
      if ((_DAT_800e1310 < 0) && (cVar2 = func_0x80033144(param_1,&DAT_800e1130), cVar2 != '\0')) {
        *(undefined4 *)(param_1 + 4) = 0x1040000;
        *(undefined1 *)(param_1 + 0x2c4) = 0;
      }
    }
  }
  if ((sVar1 == 0) && (uVar3 < 0x1389)) {
    return;
  }
LAB_8016358c:
  if (0x19 < *(byte *)(param_1 + 0x1e9)) {
    *(undefined4 *)(param_1 + 4) = 0x1010000;
    *(undefined1 *)(param_1 + 0x2b6) = 10;
  }
  return;
}

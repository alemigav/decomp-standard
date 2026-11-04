/* FUN_80162ea8
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x80162ea8  body 0x80162ea8..0x80163037  size 400 B
 * body sha256 961de0bd4043dde4ba18a19ffdfca26de5cc166005cad5fe70ad1bf71a05358a
 * provider record sha256 e0058006363c3f89e08ebbdc5739cd823253ed0e1bdaae223a36ba0b2120f164
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_80162ea8(int param_1)

{
  short sVar3;
  char cVar4;
  uint uVar1;
  int iVar2;
  undefined1 uVar5;
  
  sVar3 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x300);
  if (-1 < _DAT_800e1322) {
    if ((_DAT_800e1322 < 0x14) && (cVar4 = func_0x80033144(param_1,&DAT_800e1130), cVar4 == '\0')) {
      if (*(char *)(param_1 + 0x2b8) != '\0') {
        return 0;
      }
      if (sVar3 != 0) {
        return 0;
      }
      if (*(uint *)(param_1 + 0x28c) < 0xdac) {
        uVar5 = 6;
        goto LAB_80163008;
      }
    }
    else if (*(char *)(param_1 + 0x2b4) == '\0') {
      if ((*(char *)(param_1 + 0x2b8) != '\0') && (*(char *)(param_1 + 0x2b9) != '\0')) {
        uVar1 = func_0x80033604();
        ((char *)(param_1 + 0x2b4))[(uVar1 & 1) + 4] = '\0';
        return 0xffffffff;
      }
      iVar2 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,1);
      uVar1 = 4000;
      if (iVar2 < 0) {
        uVar1 = 3000;
        cVar4 = *(char *)(param_1 + 0x2b9);
      }
      else {
        cVar4 = *(char *)(param_1 + 0x2b8);
      }
      if (cVar4 != '\0') {
        return 0;
      }
      if (sVar3 != 0) {
        return 0;
      }
      if (*(uint *)(param_1 + 0x28c) < uVar1) {
        uVar5 = 4;
LAB_80163008:
        *(undefined1 *)(param_1 + 5) = uVar5;
        *(undefined2 *)(param_1 + 6) = 0;
        return 1;
      }
    }
    else {
      if (*(char *)(param_1 + 0x2b8) != '\0') {
        return 0;
      }
      if (sVar3 != 0) {
        return 0;
      }
      if (*(uint *)(param_1 + 0x28c) < 3000) {
        uVar5 = 5;
        goto LAB_80163008;
      }
    }
  }
  return 0;
}

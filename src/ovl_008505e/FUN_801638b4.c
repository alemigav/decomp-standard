/* FUN_801638b4
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x801638b4  body 0x801638b4..0x80163c43  size 912 B
 * body sha256 b74073e5b0e31cbc9f9f418f87ac4a1bb3dde2243987415f52395f35e8b52ee9
 * provider record sha256 3d8e3fecd9c48c3a1cfebf48d2fcbe9c8e26d2e1f3c08e0188b5f4725af129ec
 * callees 10 direct (10 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801638b4(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  byte *pbVar2;
  char cVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  
  if (*(char *)(param_1 + 7) == '\0') {
    *(undefined1 *)(param_1 + 7) = 1;
    *(undefined1 *)(param_1 + 700) = 0;
    *(undefined2 *)(param_1 + 0x1e0) = 0;
    *(undefined1 *)(param_1 + 0x206) = 0xc;
    *(undefined4 *)(param_1 + 0x1e8) = 0x17001f00;
    func_0x80089d54();
    *(undefined1 *)(param_1 + 699) = 0;
    _DAT_800e1380 = param_1;
    func_0x800331fc(0x800e1130,param_2,param_3,0);
    _DAT_800e1354 = *(undefined4 *)(param_1 + 0x224);
    _DAT_800e1358 = *(undefined4 *)(param_1 + 0x228);
    DAT_800e139f = DAT_800e139f | 0x80;
    _DAT_800e1134 = 0x6000000;
    _DAT_800e1196 = *(short *)(param_1 + 0x66) + 0x800;
    func_0x80052d10(0x1e,0x32,0x96,0);
    func_0x80052c6c(8,0xfa,0x1e);
    func_0x80052bd0(5,0x32);
    func_0x80052c6c(0x3c,0x78,0x32);
    func_0x80052bd0(5,0x46);
    func_0x80052bd0(5,0x55);
    func_0x80052bd0(0x14,100);
    func_0x80052d10(8,100,0xfa,0x71);
    func_0x80052d10(0x3c,0xfa,0,0x79);
  }
  else {
    func_0x800331fc(0x800e1130,param_2,param_3,0);
    func_0x8003331c(param_1,param_2,param_3,0);
    iVar1 = func_0x80089d54(param_1,param_2,param_3,0x80);
    if (iVar1 != 0) {
      *(undefined2 *)(param_1 + 6) = 0x100;
      *(undefined4 *)(param_1 + 0x1e8) = 0x18001f00;
      func_0x800334c8(param_1,param_2,param_3,0);
      func_0x80089d54(param_1,param_2,param_3,0x80);
      *(undefined1 *)(param_1 + 699) = 0;
      return;
    }
    cVar3 = *(char *)(param_1 + 0x1e9);
    if (cVar3 == 'b') {
      *(undefined1 *)(param_1 + 699) = 0x12;
      iVar1 = *(int *)(param_1 + 0x234);
      *(uint *)(iVar1 + 0x5e0) = *(uint *)(iVar1 + 0x5e0) | 0x80;
      *(undefined4 *)(iVar1 + 0x710) = 0x60;
      *(undefined4 *)(iVar1 + 0x714) = 0x101010;
      cVar3 = *(char *)(param_1 + 0x1e9);
    }
    if (cVar3 == 'f') {
      pbVar2 = &DAT_80166dd8;
      uVar4 = 0;
      do {
        puVar6 = (uint *)(_DAT_800e1364 + (uint)*pbVar2 * 0x178);
        uVar5 = uVar4 + 1;
        puVar6[0x4c] = 0x60;
        puVar6[0x4d] = 0x101010;
        *puVar6 = *puVar6 | 0x80;
        pbVar2 = &DAT_80166dd9 + uVar4;
        uVar4 = uVar5;
      } while (uVar5 < 4);
    }
  }
  cVar3 = *(char *)(param_1 + 0x206);
  if ((*(char *)(param_1 + 0x206) == '\0') || ((DAT_800e1138 & 1) != 0)) {
    if (*(char *)(param_1 + 700) == '\0') {
      *(undefined1 *)(param_1 + 700) = 1;
      _DAT_800e10ec = _DAT_800e10ec | 0x4000100;
      _DAT_800e1128 = _DAT_800e1128 | 0x40;
    }
    func_0x80032bd8(param_1,0,0);
    *(short *)(param_1 + 0x1e2) = *(short *)(param_1 + 0x1e2) + 0x28;
    if ((int)*(short *)(param_1 + 0x25e) <= *(int *)(param_1 + 0x2c)) {
      *(int *)(param_1 + 0x2c) = (int)*(short *)(param_1 + 0x25e);
      *(undefined2 *)(param_1 + 0x1e2) = 0;
      *(undefined1 *)(param_1 + 0x2b5) = 0;
    }
    if ((DAT_800e1138 & 1) == 0) goto LAB_80163bf0;
    cVar3 = *(char *)(param_1 + 0x206);
  }
  *(char *)(param_1 + 0x206) = cVar3 + -1;
LAB_80163bf0:
  FUN_80166980(param_1,4,0);
  FUN_80166980(param_1,8,4);
  FUN_80166980(param_1,8,4);
  func_0x80033648(param_1);
  return;
}

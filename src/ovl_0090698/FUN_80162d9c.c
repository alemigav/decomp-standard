/* FUN_80162d9c
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80162d9c  body 0x80162d9c..0x80162f3f  size 420 B
 * body sha256 33ce8232c9103bcfa444a5743fa07f1cea935d477bce1ac28a483de50ed2b7dc
 * provider record sha256 ade0f030e59ecb3f039e81d25993142419c4b535574d2a5e2503be71e622f64e
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80162d9c(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  short sVar4;
  char cVar5;
  int iVar6;
  undefined1 auStack_40 [32];
  short local_20;
  short local_1e;
  undefined2 local_1c;
  
  if (*(char *)(param_1 + 0x2d3) == '\0') {
    iVar6 = -0x7ff1eed0;
  }
  else {
    iVar6 = _DAT_800e13ec;
  }
  bVar1 = *(byte *)(param_1 + 6);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 == 2) {
        *(undefined4 *)(param_1 + 4) = 0x1000000;
        *(undefined2 *)(param_1 + 0x2ba) = 0;
        return;
      }
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    *(undefined4 *)(param_1 + 0x1e8) = 0x8000300;
    *(undefined1 *)(param_1 + 6) = 1;
    local_1e = func_0x80032d14((int)*(short *)(param_1 + 0x2a),(int)*(short *)(param_1 + 0x32),
                               (int)*(short *)(iVar6 + 0x2a),(int)*(short *)(iVar6 + 0x32));
    local_20 = 0;
    uVar2 = func_0x80033604();
    uVar3 = func_0x80033604();
    local_1c = 0;
    local_1e = local_1e + (uVar2 & 0xff) + 0x380 + (uVar3 & 1) * 0x800;
    *(short *)(param_1 + 500) = local_1e;
    func_0x80040e58(&local_20,auStack_40);
    uVar2 = func_0x80033604();
    local_20 = (uVar2 & 0x3f) + 400;
    local_1e = 0;
    local_1c = 0;
    func_0x8004276c(auStack_40,&local_20,param_1 + 0x1e0);
  }
  sVar4 = FUN_80166b04(param_1,0x60);
  *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + sVar4;
  func_0x80032b5c(param_1,(int)*(short *)(param_1 + 0x2b6) + (int)*(short *)(param_1 + 500));
  cVar5 = func_0x80089d54(param_1,param_2,param_3,0x400);
  *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar5;
  return;
}

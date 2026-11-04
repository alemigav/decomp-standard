/* FUN_80162920
 * image   ovl_0095446 (ovl), base 0x80161cf0
 * address 0x80162920  body 0x80162920..0x80162b43  size 548 B
 * body sha256 43349ed9c64b9a530988ccfaf52cc00d48b7aaa9715eee9d3037e7fcd16bd46d
 * provider record sha256 cbe8a73f441a276ca628292a3759ce5266e2ea4bf6cf56b44f52e4c4aad12ae0
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80162920(int param_1)

{
  short sVar2;
  short sVar3;
  short sVar4;
  int iVar1;
  uint uVar5;
  undefined2 local_50;
  undefined2 local_4e;
  undefined2 local_4c;
  int local_48 [2];
  int local_40;
  undefined1 auStack_38 [32];
  
  uVar5 = *(uint *)(param_1 + 0x28c);
  sVar2 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x4c8);
  sVar3 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x338);
  sVar4 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x400);
  if (sVar4 != 0) {
    *(short *)(param_1 + 0x2b6) = *(short *)(param_1 + 0x2b6) + 1;
  }
  if (*(char *)(param_1 + 0x2b8) != '\0') {
    *(char *)(param_1 + 0x2b8) = *(char *)(param_1 + 0x2b8) + -1;
  }
  if (((sVar2 != 0) && (uVar5 < 6000)) && (0x3c < *(ushort *)(param_1 + 0x2b6))) {
    *(undefined4 *)(param_1 + 4) = 0x1020000;
  }
  func_0x80040e58(param_1 + 100,auStack_38);
  local_50 = 2000;
  local_4e = 0;
  local_4c = 0;
  func_0x80042824(auStack_38,&local_50,local_48);
  local_48[0] = local_48[0] + *(int *)(param_1 + 0x28);
  local_40 = local_40 + *(int *)(param_1 + 0x30);
  if (((DAT_800e1126 < 5) && (*(short *)(param_1 + 0x2b4) == 0)) &&
     (iVar1 = func_0x800667d4(local_48,400,
                              1 << (((int)*(short *)(param_1 + 0x25e) / 0x708) * -0x10000 >> 0x10 &
                                   0x1fU),0x400), iVar1 == 0)) {
    *(undefined4 *)(param_1 + 4) = 0x1060000;
  }
  if (sVar3 == 0) {
    if (((uVar5 < 0xdac) && (DAT_800e139f == '\0')) && (*(char *)(param_1 + 0x2b9) == '\0')) {
      *(undefined4 *)(param_1 + 4) = 0x1030000;
    }
    if (uVar5 < 2000) {
      *(undefined4 *)(param_1 + 4) = 0x1090000;
    }
  }
  return;
}

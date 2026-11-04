/* FUN_80165584
 * image   ovl_0095446 (ovl), base 0x80161cf0
 * address 0x80165584  body 0x80165584..0x80165953  size 976 B
 * body sha256 f0e90271668b3a0f4d0d3b9926fac2d355b5184b0109564a5cfdfac3c7e203f1
 * provider record sha256 fd77821381bf2c052befef24f6e47be6e1a45d678da6a4b6377a8bc8799cab4b
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80165584(int param_1)

{
  byte bVar1;
  char cVar2;
  short sVar3;
  undefined2 uVar6;
  uint uVar4;
  ushort uVar7;
  uint uVar5;
  int iVar8;
  short local_60;
  short local_5e;
  short local_5c;
  short local_58 [2];
  short local_54;
  short local_50 [2];
  short local_4c;
  undefined1 auStack_48 [32];
  
  bVar1 = *(byte *)(param_1 + 0x2bf);
  if (bVar1 == 1) {
    *(undefined1 *)(param_1 + 0x2bf) = 2;
    *(undefined1 *)(param_1 + 0x2c0) = 0;
    uVar6 = func_0x80032d14((int)*(short *)(param_1 + 0x2a),(int)*(short *)(param_1 + 0x32),
                            (int)_DAT_800e115a,(int)_DAT_800e1162);
    *(undefined2 *)(param_1 + 0x2c2) = uVar6;
  }
  else {
    if (bVar1 < 2) {
      return;
    }
    if (bVar1 != 2) {
      return;
    }
  }
  local_60 = 0;
  sVar3 = *(short *)(param_1 + 0x2c2);
  local_5c = 0;
  local_5e = sVar3;
  func_0x80040e58(&local_60,auStack_48);
  local_5e = 200;
  local_60 = *(char *)(param_1 + 0x2c0) * -200 + -200;
  func_0x8004276c(auStack_48,&local_60,local_58);
  local_60 = -200;
  local_5e = 0;
  local_5c = 0;
  func_0x8004276c(auStack_48,&local_60,local_50);
  local_60 = *(short *)(param_1 + 0x2a) + local_58[0];
  local_5e = *(undefined2 *)(*(int *)(param_1 + 0x234) + 0x52);
  local_5c = *(short *)(param_1 + 0x32) + local_54;
  uVar4 = func_0x80033604();
  iVar8 = (int)sVar3;
  func_0x80037780((0x1080 - (uVar4 & 0xff)) + *(char *)(param_1 + 0x2c0) * -0xa0 | 0x90000,iVar8,
                  0x800e9028,&local_60);
  *(char *)(param_1 + 0x2c0) = *(char *)(param_1 + 0x2c0) + '\x01';
  uVar7 = func_0x80033604();
  local_60 = (local_50[0] + *(short *)(param_1 + 0x2a) + local_58[0]) - ((uVar7 & 0xff) - 0x80);
  uVar7 = func_0x80033604();
  local_5c = (local_4c + *(short *)(param_1 + 0x32) + local_54) - ((uVar7 & 0xff) - 0x80);
  uVar4 = func_0x80033604();
  uVar5 = func_0x80033604();
  func_0x80037780((9 - (uVar4 & 1)) * 0x10000 |
                  (0x1080 - (uVar5 & 0xff)) + *(char *)(param_1 + 0x2c0) * -0xa0,iVar8,0x800e9028,
                  &local_60);
  if (*(char *)(param_1 + 0x2c0) == '\x01') {
    func_0x80037780(0xa1000,(int)(short)(sVar3 + 0x800),0x800e9028,&local_60);
  }
  *(char *)(param_1 + 0x2c0) = *(char *)(param_1 + 0x2c0) + '\x01';
  local_60 = *(short *)(param_1 + 0x2a) + local_58[0] + local_50[0] * 2;
  local_5c = *(short *)(param_1 + 0x32) + local_54 + local_4c * 2;
  uVar4 = func_0x80033604();
  func_0x80037780((0x1080 - (uVar4 & 0xff)) + *(char *)(param_1 + 0x2c0) * -0xa0 | 0x90000,iVar8,
                  0x800e9028,&local_60);
  *(char *)(param_1 + 0x2c0) = *(char *)(param_1 + 0x2c0) + '\x01';
  uVar7 = func_0x80033604();
  local_60 = (*(short *)(param_1 + 0x2a) + local_58[0] + local_50[0] * 3) - ((uVar7 & 0xff) - 0x80);
  uVar7 = func_0x80033604();
  local_5c = (*(short *)(param_1 + 0x32) + local_54 + local_4c * 3) - ((uVar7 & 0xff) - 0x80);
  uVar4 = func_0x80033604();
  uVar5 = func_0x80033604();
  func_0x80037780((9 - (uVar4 & 1)) * 0x10000 |
                  (0x1080 - (uVar5 & 0xff)) + *(char *)(param_1 + 0x2c0) * -0xa0,iVar8,0x800e9028,
                  &local_60);
  cVar2 = *(char *)(param_1 + 0x2c0);
  *(char *)(param_1 + 0x2c0) = cVar2 + '\x01';
  if ('\f' < cVar2) {
    *(undefined1 *)(param_1 + 0x2bf) = 0;
  }
  return;
}

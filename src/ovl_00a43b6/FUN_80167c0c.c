/* FUN_80167c0c
 * image   ovl_00a43b6 (ovl), base 0x80161cf0
 * address 0x80167c0c  body 0x80167c0c..0x80168297  size 1676 B
 * body sha256 c4d4c01d84f7ffa3ac775b09453fc2ce8c0c5478b57fae9115a491da3e20cc06
 * provider record sha256 a5a6746840bbbd82e6cf18e2969fbf49a2e3ccfba6b10c4ab9ee0ae39742637a
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80167c0c(int param_1)

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
  short local_58;
  short local_56;
  short local_54;
  short local_50 [2];
  short local_4c;
  undefined1 auStack_48 [32];
  
  bVar1 = *(byte *)(param_1 + 0x2c5);
  if (bVar1 == 1) {
    *(undefined1 *)(param_1 + 0x2c5) = 2;
    *(undefined1 *)(param_1 + 0x2c6) = 0;
    uVar6 = func_0x80032d14((int)*(short *)(param_1 + 0x2a),(int)*(short *)(param_1 + 0x32),
                            (int)_DAT_800e115a,(int)_DAT_800e1162);
    *(undefined2 *)(param_1 + 0x2c8) = uVar6;
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
  sVar3 = *(short *)(param_1 + 0x2c8);
  local_5c = 0;
  local_5e = sVar3;
  func_0x80040e58(&local_60,auStack_48);
  local_5e = 200;
  local_60 = *(char *)(param_1 + 0x2c6) * -100;
  func_0x8004276c(auStack_48,&local_60,&local_58);
  local_60 = -100;
  local_5e = 0xfe0c;
  local_5c = 0;
  if ((uint)*(byte *)(param_1 + 0x26e) % 3 == 0) {
    local_5e = 500;
  }
  func_0x8004276c(auStack_48,&local_60,local_50);
  local_60 = *(short *)(param_1 + 0x2a) + local_58;
  local_5e = *(short *)(*(int *)(param_1 + 0x234) + 0x342) + local_56;
  local_5c = *(short *)(param_1 + 0x32) + local_54;
  uVar4 = func_0x80033604();
  iVar8 = (int)sVar3;
  func_0x80037780((0x65c - (uVar4 & 0xff)) + *(char *)(param_1 + 0x2c6) * -0x24 | 0x10000,iVar8,
                  0x800e9028,&local_60);
  *(char *)(param_1 + 0x2c6) = *(char *)(param_1 + 0x2c6) + '\x01';
  uVar7 = func_0x80033604();
  local_60 = (local_50[0] + *(short *)(param_1 + 0x2a) + local_58) - ((uVar7 & 0xff) - 0x80);
  uVar7 = func_0x80033604();
  local_5c = (local_4c + *(short *)(param_1 + 0x32) + local_54) - ((uVar7 & 0xff) - 0x80);
  uVar4 = func_0x80033604();
  uVar5 = func_0x80033604();
  func_0x80037780((1 - (uVar4 & 1)) * 0x10000 |
                  (0x65c - (uVar5 & 0xff)) + *(char *)(param_1 + 0x2c6) * -0x24,iVar8,0x800e9028,
                  &local_60);
  if (*(char *)(param_1 + 0x2c6) == '\x01') {
    func_0x80037780(0x217d0,(int)(short)(sVar3 + 0x800),0x800e9028,&local_60);
    func_0x80037780(0x20c18,(int)(short)(sVar3 + 0x800),0x800e9028,&local_60);
  }
  *(char *)(param_1 + 0x2c6) = *(char *)(param_1 + 0x2c6) + '\x01';
  local_60 = *(short *)(param_1 + 0x2a) + local_58 + local_50[0] * 2;
  local_5c = *(short *)(param_1 + 0x32) + local_54 + local_4c * 2;
  uVar4 = func_0x80033604();
  func_0x80037780((0x65c - (uVar4 & 0xff)) + *(char *)(param_1 + 0x2c6) * -0x24 | 0x10000,iVar8,
                  0x800e9028,&local_60);
  *(char *)(param_1 + 0x2c6) = *(char *)(param_1 + 0x2c6) + '\x01';
  uVar7 = func_0x80033604();
  local_60 = (*(short *)(param_1 + 0x2a) + local_58 + local_50[0] * 3) - ((uVar7 & 0xff) - 0x80);
  uVar7 = func_0x80033604();
  local_5c = (*(short *)(param_1 + 0x32) + local_54 + local_4c * 3) - ((uVar7 & 0xff) - 0x80);
  uVar4 = func_0x80033604();
  uVar5 = func_0x80033604();
  func_0x80037780((1 - (uVar4 & 1)) * 0x10000 |
                  (0x65c - (uVar5 & 0xff)) + *(char *)(param_1 + 0x2c6) * -0x24,iVar8,0x800e9028,
                  &local_60);
  *(char *)(param_1 + 0x2c6) = *(char *)(param_1 + 0x2c6) + '\x01';
  local_60 = *(short *)(param_1 + 0x2a) + local_58 + local_50[0] * 4;
  local_5c = *(short *)(param_1 + 0x32) + local_54 + local_4c * 4;
  uVar4 = func_0x80033604();
  func_0x80037780((0x65c - (uVar4 & 0xff)) + *(char *)(param_1 + 0x2c6) * -0x24 | 0x10000,iVar8,
                  0x800e9028,&local_60);
  *(char *)(param_1 + 0x2c6) = *(char *)(param_1 + 0x2c6) + '\x01';
  uVar7 = func_0x80033604();
  local_60 = (*(short *)(param_1 + 0x2a) + local_58 + local_50[0] * 5) - ((uVar7 & 0xff) - 0x80);
  uVar7 = func_0x80033604();
  local_5c = (*(short *)(param_1 + 0x32) + local_54 + local_4c * 5) - ((uVar7 & 0xff) - 0x80);
  uVar4 = func_0x80033604();
  uVar5 = func_0x80033604();
  func_0x80037780((1 - (uVar4 & 1)) * 0x10000 |
                  (0x65c - (uVar5 & 0xff)) + *(char *)(param_1 + 0x2c6) * -0x24,iVar8,0x800e9028,
                  &local_60);
  *(char *)(param_1 + 0x2c6) = *(char *)(param_1 + 0x2c6) + '\x01';
  local_60 = *(short *)(param_1 + 0x2a) + local_58 + local_50[0] * 6;
  local_5c = *(short *)(param_1 + 0x32) + local_54 + local_4c * 6;
  uVar4 = func_0x80033604();
  func_0x80037780((0x65c - (uVar4 & 0xff)) + *(char *)(param_1 + 0x2c6) * -0x24 | 0x10000,iVar8,
                  0x800e9028,&local_60);
  *(char *)(param_1 + 0x2c6) = *(char *)(param_1 + 0x2c6) + '\x01';
  uVar7 = func_0x80033604();
  local_60 = (*(short *)(param_1 + 0x2a) + local_58 + local_50[0] * 7) - ((uVar7 & 0xff) - 0x80);
  uVar7 = func_0x80033604();
  local_5c = (*(short *)(param_1 + 0x32) + local_54 + local_4c * 7) - ((uVar7 & 0xff) - 0x80);
  uVar4 = func_0x80033604();
  uVar5 = func_0x80033604();
  func_0x80037780((1 - (uVar4 & 1)) * 0x10000 |
                  (0x65c - (uVar5 & 0xff)) + *(char *)(param_1 + 0x2c6) * -0x1e,iVar8,0x800e9028,
                  &local_60);
  cVar2 = *(char *)(param_1 + 0x2c6);
  *(char *)(param_1 + 0x2c6) = cVar2 + '\x01';
  if ('\x10' < cVar2) {
    *(undefined1 *)(param_1 + 0x2c5) = 0;
  }
  return;
}

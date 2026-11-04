/* FUN_8016578c
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x8016578c  body 0x8016578c..0x80165e13  size 1672 B
 * body sha256 c4857a12834a9f6c968c892300e6bde0cf152e19102eaa57572ab75732b55b8c
 * provider record sha256 8dda30e33841af4c02b2a0a4b4da43b88cb0839c71d40c83b74af149e445fb6f
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8016578c(int param_1)

{
  byte bVar1;
  short sVar2;
  undefined2 uVar5;
  uint uVar3;
  ushort uVar6;
  uint uVar4;
  int iVar7;
  short local_60;
  short local_5e;
  short local_5c;
  short local_58;
  short local_56;
  short local_54;
  short local_50 [2];
  short local_4c;
  undefined1 auStack_48 [32];
  
  bVar1 = *(byte *)(param_1 + 0x2d8);
  if (bVar1 == 1) {
    *(undefined1 *)(param_1 + 0x2d8) = 2;
    *(undefined1 *)(param_1 + 0x2d9) = 0;
    uVar5 = func_0x80032d14((int)*(short *)(param_1 + 0x2a),(int)*(short *)(param_1 + 0x32),
                            (int)_DAT_800e115a,(int)_DAT_800e1162);
    *(undefined2 *)(param_1 + 0x2da) = uVar5;
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
  sVar2 = *(short *)(param_1 + 0x2da);
  local_5c = 0;
  local_5e = sVar2;
  func_0x80040e58(&local_60,auStack_48);
  local_5e = 200;
  local_60 = (ushort)*(byte *)(param_1 + 0x2d9) * -100;
  func_0x8004276c(auStack_48,&local_60,&local_58);
  local_60 = -100;
  local_5e = 0xfe0c;
  local_5c = 0;
  if ((uint)*(byte *)(param_1 + 0x26e) % 3 == 0) {
    local_5e = 500;
  }
  func_0x8004276c(auStack_48,&local_60,local_50);
  local_60 = *(short *)(param_1 + 0x2a) + local_58;
  local_5e = *(short *)(*(int *)(param_1 + 0x234) + 0xd8a) + local_56;
  local_5c = *(short *)(param_1 + 0x32) + local_54;
  uVar3 = func_0x80033604();
  iVar7 = (int)sVar2;
  func_0x80037780((0x65c - (uVar3 & 0xff)) + (uint)*(byte *)(param_1 + 0x2d9) * -0x24 | 0x10000,
                  iVar7,0x800e9028,&local_60);
  *(char *)(param_1 + 0x2d9) = *(char *)(param_1 + 0x2d9) + '\x01';
  uVar6 = func_0x80033604();
  local_60 = (local_50[0] + *(short *)(param_1 + 0x2a) + local_58) - ((uVar6 & 0xff) - 0x80);
  uVar6 = func_0x80033604();
  local_5c = (local_4c + *(short *)(param_1 + 0x32) + local_54) - ((uVar6 & 0xff) - 0x80);
  uVar3 = func_0x80033604();
  uVar4 = func_0x80033604();
  func_0x80037780((1 - (uVar3 & 1)) * 0x10000 |
                  (0x65c - (uVar4 & 0xff)) + (uint)*(byte *)(param_1 + 0x2d9) * -0x24,iVar7,
                  0x800e9028,&local_60);
  if (*(char *)(param_1 + 0x2d9) == '\x01') {
    func_0x80037780(0x217d0,(int)(short)(sVar2 + 0x800),0x800e9028,&local_60);
    func_0x80037780(0x20c18,(int)(short)(sVar2 + 0x800),0x800e9028,&local_60);
  }
  *(char *)(param_1 + 0x2d9) = *(char *)(param_1 + 0x2d9) + '\x01';
  local_60 = *(short *)(param_1 + 0x2a) + local_58 + local_50[0] * 2;
  local_5c = *(short *)(param_1 + 0x32) + local_54 + local_4c * 2;
  uVar3 = func_0x80033604();
  func_0x80037780((0x65c - (uVar3 & 0xff)) + (uint)*(byte *)(param_1 + 0x2d9) * -0x24 | 0x10000,
                  iVar7,0x800e9028,&local_60);
  *(char *)(param_1 + 0x2d9) = *(char *)(param_1 + 0x2d9) + '\x01';
  uVar6 = func_0x80033604();
  local_60 = (*(short *)(param_1 + 0x2a) + local_58 + local_50[0] * 3) - ((uVar6 & 0xff) - 0x80);
  uVar6 = func_0x80033604();
  local_5c = (*(short *)(param_1 + 0x32) + local_54 + local_4c * 3) - ((uVar6 & 0xff) - 0x80);
  uVar3 = func_0x80033604();
  uVar4 = func_0x80033604();
  func_0x80037780((1 - (uVar3 & 1)) * 0x10000 |
                  (0x65c - (uVar4 & 0xff)) + (uint)*(byte *)(param_1 + 0x2d9) * -0x24,iVar7,
                  0x800e9028,&local_60);
  *(char *)(param_1 + 0x2d9) = *(char *)(param_1 + 0x2d9) + '\x01';
  local_60 = *(short *)(param_1 + 0x2a) + local_58 + local_50[0] * 4;
  local_5c = *(short *)(param_1 + 0x32) + local_54 + local_4c * 4;
  uVar3 = func_0x80033604();
  func_0x80037780((0x65c - (uVar3 & 0xff)) + (uint)*(byte *)(param_1 + 0x2d9) * -0x24 | 0x10000,
                  iVar7,0x800e9028,&local_60);
  *(char *)(param_1 + 0x2d9) = *(char *)(param_1 + 0x2d9) + '\x01';
  uVar6 = func_0x80033604();
  local_60 = (*(short *)(param_1 + 0x2a) + local_58 + local_50[0] * 5) - ((uVar6 & 0xff) - 0x80);
  uVar6 = func_0x80033604();
  local_5c = (*(short *)(param_1 + 0x32) + local_54 + local_4c * 5) - ((uVar6 & 0xff) - 0x80);
  uVar3 = func_0x80033604();
  uVar4 = func_0x80033604();
  func_0x80037780((1 - (uVar3 & 1)) * 0x10000 |
                  (0x65c - (uVar4 & 0xff)) + (uint)*(byte *)(param_1 + 0x2d9) * -0x24,iVar7,
                  0x800e9028,&local_60);
  *(char *)(param_1 + 0x2d9) = *(char *)(param_1 + 0x2d9) + '\x01';
  local_60 = *(short *)(param_1 + 0x2a) + local_58 + local_50[0] * 6;
  local_5c = *(short *)(param_1 + 0x32) + local_54 + local_4c * 6;
  uVar3 = func_0x80033604();
  func_0x80037780((0x65c - (uVar3 & 0xff)) + (uint)*(byte *)(param_1 + 0x2d9) * -0x24 | 0x10000,
                  iVar7,0x800e9028,&local_60);
  *(char *)(param_1 + 0x2d9) = *(char *)(param_1 + 0x2d9) + '\x01';
  uVar6 = func_0x80033604();
  local_60 = (*(short *)(param_1 + 0x2a) + local_58 + local_50[0] * 7) - ((uVar6 & 0xff) - 0x80);
  uVar6 = func_0x80033604();
  local_5c = (*(short *)(param_1 + 0x32) + local_54 + local_4c * 7) - ((uVar6 & 0xff) - 0x80);
  uVar3 = func_0x80033604();
  uVar4 = func_0x80033604();
  func_0x80037780((1 - (uVar3 & 1)) * 0x10000 |
                  (0x65c - (uVar4 & 0xff)) + (uint)*(byte *)(param_1 + 0x2d9) * -0x1e,iVar7,
                  0x800e9028,&local_60);
  bVar1 = *(byte *)(param_1 + 0x2d9);
  *(byte *)(param_1 + 0x2d9) = bVar1 + 1;
  if (0x10 < bVar1) {
    *(undefined1 *)(param_1 + 0x2d8) = 0;
  }
  return;
}

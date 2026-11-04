/* FUN_80162094
 * image   ovl_007fc12 (ovl), base 0x80161cf0
 * address 0x80162094  body 0x80162094..0x80162a2b  size 2456 B
 * body sha256 d66afa7f36421654adcbcf0f1b3a93f18a96695a9f5e4f295d8797e18e373631
 * provider record sha256 c6afd2baf385ca39e1e4ee09da67ffac50dacf51df51f830580e1979cd38448a
 * callees 6 direct (5 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80162094(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 uVar1;
  uint uVar2;
  uint uVar3;
  byte bVar5;
  uint uVar4;
  char cVar6;
  int iVar7;
  int unaff_s3;
  undefined4 local_28;
  undefined4 local_24;
  
  local_28 = 0x20002;
  local_24 = 0x20200;
  param_1[1] = 0x1000000;
  *(undefined2 *)(param_1 + 0x9b) = 0;
  *(undefined2 *)(param_1 + 0x9a) = 0;
  *(undefined2 *)(param_1 + 0x99) = 0;
  *(undefined1 *)((int)param_1 + 0x26f) = 0;
  uVar2 = func_0x80033604();
  uVar3 = func_0x80033604();
  *(undefined2 *)((int)param_1 + 0x1f2) =
       *(undefined2 *)(&DAT_8016df90 + ((int)(uVar2 & 0xff) >> (uVar3 & 3) & 0xfU) * 2);
  if ((_DAT_800e10ec & 0x20) != 0) {
    uVar2 = func_0x80033604();
    uVar3 = func_0x80033604();
    *(undefined2 *)((int)param_1 + 0x1f2) =
         *(undefined2 *)(&DAT_8016dfb0 + ((int)(uVar2 & 0xff) >> (uVar3 & 3) & 0xfU) * 2);
    if ((_DAT_800e10ec & 0x20) != 0) goto LAB_801621bc;
  }
  if (DAT_800e1126 < 4) {
    *(short *)((int)param_1 + 0x1f2) = *(short *)((int)param_1 + 0x1f2) + 0xf;
  }
LAB_801621bc:
  uVar2 = param_1[0x8d];
  *(undefined1 *)((int)param_1 + 0x1ed) = 0xd;
  *(undefined1 *)((int)param_1 + 0x1ee) = 0xd;
  *(undefined1 *)((int)param_1 + 0x1ef) = 0xd;
  *(undefined1 *)((int)param_1 + 0x25d) = 8;
  *(undefined1 *)(param_1 + 0x97) = 0;
  *(undefined2 *)(uVar2 + 0xcf4) = 0x60;
  *(undefined2 *)(uVar2 + 0xcf6) = 0x60;
  *(undefined2 *)(uVar2 + 0xcf8) = 0x200;
  *(undefined2 *)(uVar2 + 0xcf0) = 0;
  *(undefined2 *)(uVar2 + 0xcf2) = 0;
  *(undefined2 *)(uVar2 + 0xcfa) = 0x138;
  uVar2 = func_0x80033604();
  uVar3 = func_0x80033604();
  uVar1 = *(undefined1 *)((int)&local_28 + ((int)(uVar2 & 0xff) >> (uVar3 & 3) & 7U));
  *(undefined2 *)((int)param_1 + 0x2b6) = 0;
  *(undefined1 *)((int)param_1 + 0x2b5) = 0;
  *(undefined1 *)((int)param_1 + 0x2be) = 0;
  *(undefined1 *)(param_1 + 0xad) = uVar1;
  bVar5 = func_0x80033604();
  *(byte *)((int)param_1 + 0x2bf) = (bVar5 & 0xf) + 0x10;
  *(undefined1 *)(param_1 + 0xb3) = 0;
  *(undefined1 *)((int)param_1 + 0x2cd) = 0;
  *(undefined2 *)((int)param_1 + 0x2d2) = 0;
  *(undefined1 *)((int)param_1 + 0x2d5) = 0;
  *(undefined1 *)((int)param_1 + 0x2d6) = 0;
  *(undefined1 *)((int)param_1 + 0x2d7) = 0;
  *(undefined1 *)(param_1 + 0xb6) = 0;
  if (*(char *)(param_1 + 2) == '\x11') {
    *(undefined2 *)((int)param_1 + 0x1f2) = 0xfa;
    *(ushort *)((int)param_1 + 0x2b6) = *(ushort *)((int)param_1 + 0x2b6) | 0x8000;
  }
  uVar2 = func_0x80033604();
  uVar3 = func_0x80033604();
  iVar7 = (int)(uVar2 & 0xff) >> (uVar3 & 3);
  if (iVar7 == (iVar7 / 3) * 3) {
    *(ushort *)((int)param_1 + 0x2b6) = *(ushort *)((int)param_1 + 0x2b6) | 0x8000;
    bVar5 = func_0x80033604();
    *(byte *)((int)param_1 + 0x2bf) = (bVar5 & 0xf) + 0x20;
  }
  *(undefined2 *)(param_1 + 0x4d) = 0xfa24;
  *(undefined2 *)((int)param_1 + 0x13a) = 0x5dc;
  *(undefined2 *)((int)param_1 + 0x136) = 500;
  *(undefined2 *)(param_1 + 0x4e) = 500;
  *(undefined2 *)(param_1 + 0x4b) = 500;
  *(undefined2 *)((int)param_1 + 0x12e) = 500;
  *(undefined2 *)((int)param_1 + 0x28a) = 500;
  param_1[0xa1] = 1;
  *(undefined2 *)(param_1 + 0x4c) = 0;
  *(undefined2 *)((int)param_1 + 0x132) = 0;
  *param_1 = *param_1 | 0xc000000;
  if (*(char *)(param_1 + 2) == '\x13') {
    *(undefined2 *)((int)param_1 + 0x27a) = 0xe66;
  }
  if (*(char *)(param_1 + 2) == '\x1e') {
    *(undefined2 *)((int)param_1 + 0x27a) = 0xe66;
  }
  param_1[0x7a] = 0x1000000;
  if ((*(ushort *)((int)param_1 + 0x1aa) & 0x3f) == 2) {
    param_1[0x7a] = 0x16000000;
    param_1[1] = 0x1070000;
    *(ushort *)((int)param_1 + 0x2b6) = *(ushort *)((int)param_1 + 0x2b6) | 4;
  }
  if ((*(ushort *)((int)param_1 + 0x1aa) & 0x3f) == 4) {
    param_1[0x7a] = 0x17000000;
    param_1[1] = 0x1070000;
  }
  if ((*(ushort *)((int)param_1 + 0x1aa) & 0x3f) == 5) {
    param_1[0x7a] = 0x16000000;
    param_1[1] = 0x1070000;
    *(undefined2 *)((int)param_1 + 0x1aa) = 0x4002;
    *(undefined2 *)((int)param_1 + 0x1f2) = 0xffff;
    *(ushort *)((int)param_1 + 0x2b6) = *(ushort *)((int)param_1 + 0x2b6) | 4;
    *(uint *)(param_1[0x8d] + 0xbc0) = *(uint *)(param_1[0x8d] + 0xbc0) | 0x4000;
  }
  if ((*(ushort *)((int)param_1 + 0x1aa) & 0x3f) == 7) {
    param_1[0x7a] = 0x17000000;
    param_1[1] = 0x1070000;
    *(undefined2 *)((int)param_1 + 0x1aa) = 0x4004;
    *(undefined2 *)((int)param_1 + 0x1f2) = 0xffff;
    *(uint *)(param_1[0x8d] + 0xbc0) = *(uint *)(param_1[0x8d] + 0xbc0) | 0x4000;
  }
  if ((*(ushort *)((int)param_1 + 0x1aa) & 0x3f) == 6) {
    param_1[1] = 0x1010000;
  }
  if ((*(ushort *)((int)param_1 + 0x1aa) & 0x3f) == 8) {
    param_1[0x7a] = 0x12000000;
    param_1[1] = 0x1080000;
  }
  if ((*(ushort *)((int)param_1 + 0x1aa) & 1) != 0) {
    param_1[0x7a] = 0x17000000;
    *(undefined2 *)((int)param_1 + 0x136) = 200;
    *(undefined2 *)(param_1 + 0x4e) = 200;
    *(undefined2 *)(param_1 + 0x4b) = 200;
    *(undefined2 *)((int)param_1 + 0x12e) = 200;
    *(undefined2 *)(param_1 + 0x4d) = 0xfea2;
    *(undefined2 *)((int)param_1 + 0x13a) = 0x15e;
    *(ushort *)((int)param_1 + 0x1aa) = *(ushort *)((int)param_1 + 0x1aa) | 0x2000;
    *param_1 = *param_1 & 0xf3ffffff | 0x4000000;
    iVar7 = (uint)*(ushort *)((int)param_1 + 0x1f2) << 0x10;
    *(short *)((int)param_1 + 0x1f2) = (short)((iVar7 >> 0x10) - (iVar7 >> 0x1f) >> 1);
  }
  if ((*(ushort *)((int)param_1 + 0x1aa) & 0x3f) == 1) {
    param_1[1] = 0x1020000;
  }
  if ((*(ushort *)((int)param_1 + 0x1aa) & 0x3f) == 3) {
    param_1[1] = 0x1000000;
  }
  func_0x80089d54(param_1,param_2,param_3,0x100);
  if ((*(ushort *)((int)param_1 + 0x1aa) & 0x3f) == 10) {
    *(undefined2 *)(param_1 + 0x4d) = 0xfea2;
    *(undefined2 *)((int)param_1 + 0x13a) = 0x15e;
    param_1[1] = 0x10f0000;
    uVar2 = *param_1;
    *(undefined1 *)((int)param_1 + 0x2be) = 0;
    *(undefined2 *)((int)param_1 + 0x136) = 0;
    *(undefined2 *)(param_1 + 0x4e) = 0;
    *(undefined2 *)(param_1 + 0x4b) = 0;
    *(undefined2 *)((int)param_1 + 0x12e) = 0;
    param_1[0x7a] = 0;
    *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) | 0x80;
    *param_1 = uVar2 & 0xf3ffffff | 0x4000000;
    *param_1 = uVar2 & 0xf3ffffff | 0x4000008;
    *(ushort *)((int)param_1 + 0x2b6) = *(ushort *)((int)param_1 + 0x2b6) & 0xfffb | 2;
    func_0x80089d54(param_1,param_1[0x8b],param_1[0x8c],0x100);
  }
  func_0x800339dc(param_1 + 0x82,0,0x2580190,0,param_1[0x8d] + 0x4c);
  cVar6 = *(char *)(param_1 + 2);
  if (cVar6 == '\x12') {
    uVar2 = func_0x80033604();
    if ((uVar2 & 1) != 0) {
      func_0x800341ec(param_1[0x8d] + 0xbc4,*(byte *)(param_1 + 0x68) + 2,0,
                      *(byte *)((int)param_1 + 0x1a1) + 0x1e2);
    }
    uVar2 = func_0x80033604();
    if ((uVar2 & 1) == 0) {
      func_0x800341ec(param_1[0x8d] + 4,*(byte *)(param_1 + 0x68) + 3,0,
                      *(byte *)((int)param_1 + 0x1a1) + 0x1e3);
      func_0x800341ec(param_1[0x8d] + 0x1784,*(byte *)(param_1 + 0x68) + 3,0,
                      *(byte *)((int)param_1 + 0x1a1) + 0x1e3);
      func_0x800341ec(param_1[0x8d] + 0x17c,*(byte *)(param_1 + 0x68) + 3,0,
                      *(byte *)((int)param_1 + 0x1a1) + 0x1e3);
      func_0x800341ec(param_1[0x8d] + 0x2f4,*(byte *)(param_1 + 0x68) + 3,0,
                      *(byte *)((int)param_1 + 0x1a1) + 0x1e3);
      func_0x800341ec(param_1[0x8d] + 0x46c,*(byte *)(param_1 + 0x68) + 3,0,
                      *(byte *)((int)param_1 + 0x1a1) + 0x1e3);
      func_0x800341ec(param_1[0x8d] + 0x5e4,*(byte *)(param_1 + 0x68) + 3,0,
                      *(byte *)((int)param_1 + 0x1a1) + 0x1e3);
      func_0x800341ec(param_1[0x8d] + 0x75c,*(byte *)(param_1 + 0x68) + 3,0,
                      *(byte *)((int)param_1 + 0x1a1) + 0x1e3);
      func_0x800341ec(param_1[0x8d] + 0x8d4,*(byte *)(param_1 + 0x68) + 3,0,
                      *(byte *)((int)param_1 + 0x1a1) + 0x1e3);
      func_0x800341ec(param_1[0x8d] + 0xa4c,*(byte *)(param_1 + 0x68) + 3,0,
                      *(byte *)((int)param_1 + 0x1a1) + 0x1e3);
      func_0x800341ec(param_1[0x8d] + 0xd3c,*(byte *)(param_1 + 0x68) + 3,0,
                      *(byte *)((int)param_1 + 0x1a1) + 0x1e3);
      func_0x800341ec(param_1[0x8d] + 0xeb4,*(byte *)(param_1 + 0x68) + 3,0,
                      *(byte *)((int)param_1 + 0x1a1) + 0x1e3);
      func_0x800341ec(param_1[0x8d] + 0x102c,*(byte *)(param_1 + 0x68) + 2,0,
                      *(byte *)((int)param_1 + 0x1a1) + 0x1e2);
      func_0x800341ec(param_1[0x8d] + 0x11a4,*(byte *)(param_1 + 0x68) + 3,0,
                      *(byte *)((int)param_1 + 0x1a1) + 0x1e3);
      func_0x800341ec(param_1[0x8d] + 0x131c,*(byte *)(param_1 + 0x68) + 3,0,
                      *(byte *)((int)param_1 + 0x1a1) + 0x1e3);
      func_0x800341ec(param_1[0x8d] + 0x1494,*(byte *)(param_1 + 0x68) + 2,0,
                      *(byte *)((int)param_1 + 0x1a1) + 0x1e2);
    }
    cVar6 = *(char *)(param_1 + 2);
  }
  if (cVar6 == '\x1f') {
    if ((*(byte *)((int)param_1 + 0x26b) & 0xc0) == 0) {
      uVar2 = func_0x80033604();
      uVar3 = func_0x80033604();
      uVar4 = func_0x80033604();
      unaff_s3 = (int)((uVar2 & 0xff) + ((uVar3 & 0xff) << (uVar4 & 3))) % 3;
    }
    if ((*(byte *)((int)param_1 + 0x26b) & 0x3f) != 0) {
      unaff_s3 = (*(byte *)((int)param_1 + 0x26b) & 0x3f) - 1;
    }
    func_0x8008794c(param_1,param_1[0x8d],unaff_s3);
    func_0x8008794c(param_1,param_1[0x8d] + 0x178,unaff_s3);
    func_0x8008794c(param_1,param_1[0x8d] + 0x2f0,unaff_s3);
    func_0x8008794c(param_1,param_1[0x8d] + 0x468,unaff_s3);
    func_0x8008794c(param_1,param_1[0x8d] + 0x5e0,unaff_s3);
    func_0x8008794c(param_1,param_1[0x8d] + 0x758,unaff_s3);
    func_0x8008794c(param_1,param_1[0x8d] + 0x8d0,unaff_s3);
    func_0x8008794c(param_1,param_1[0x8d] + 0xa48,unaff_s3);
    func_0x8008794c(param_1,param_1[0x8d] + 0xd38,unaff_s3);
    func_0x8008794c(param_1,param_1[0x8d] + 0xeb0,unaff_s3);
    func_0x8008794c(param_1,param_1[0x8d] + 0x11a0,unaff_s3);
    func_0x8008794c(param_1,param_1[0x8d] + 0x1318,unaff_s3);
    func_0x8008794c(param_1,param_1[0x8d] + 0x1780,unaff_s3);
  }
  if ((*(ushort *)((int)param_1 + 0x1aa) & 0x80) != 0) {
    FUN_80167910(param_1);
  }
  *(undefined4 *)(param_1[0x8d] + 0x1608) = 0;
  *(undefined4 *)(param_1[0x8d] + 0x1780) = 0;
  *(code **)((*(byte *)(param_1 + 2) - 0x10) * 4 + -0x7ff206b8) = FUN_8016c0b4;
  *(code **)((*(byte *)(param_1 + 2) - 0x10) * 4 + -0x7ff205b8) = FUN_8016caf8;
  return;
}

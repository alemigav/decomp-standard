/* FUN_80163344
 * image   ovl_0095446 (ovl), base 0x80161cf0
 * address 0x80163344  body 0x80163344..0x8016370f  size 972 B
 * body sha256 ba1f64ff2b8791664121452f4ef62be704a67b10ccd8066a44f24b9e2c3d9866
 * provider record sha256 f274fe807a3f9a36920f57d2b7a41da883e5af4594acac9468db4a5c57315326
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80163344(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  ushort uVar3;
  uint uVar2;
  byte bVar4;
  int iVar5;
  short sVar6;
  short local_20 [4];
  
  if (*(char *)(param_1 + 0x2be) < '\x03') {
    *(byte *)(param_1 + 0x2be) = *(byte *)(param_1 + 0x2be) | 0x82;
  }
  if (*(char *)(param_1 + 700) < '\x02') {
    *(undefined1 *)(param_1 + 700) = 1;
  }
  bVar4 = *(byte *)(param_1 + 6);
  if (bVar4 != 1) {
    if (1 < bVar4) {
      return;
    }
    if (bVar4 != 0) {
      return;
    }
    *(undefined4 *)(param_1 + 0x1e8) = 0x5003f00;
    *(undefined1 *)(param_1 + 6) = 1;
    if ((*(ushort *)(param_1 + 0x2ba) & 0x400) == 0) {
      *_DAT_800e13f4 = 0;
      *(ushort *)(param_1 + 0x2ba) = *(ushort *)(param_1 + 0x2ba) | 0x400;
      DAT_800e1126 = DAT_800e1126 - 1;
    }
    iVar1 = func_0x80031ff0(0x27);
    iVar5 = *(int *)(param_1 + 0x234);
    *(undefined4 *)(iVar1 + 0x28) = *(undefined4 *)(iVar5 + 0x62c);
    *(undefined4 *)(iVar1 + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
    *(undefined4 *)(iVar1 + 0x30) = *(undefined4 *)(iVar5 + 0x634);
    uVar3 = func_0x80033604();
    sVar6 = *(short *)(param_1 + 0x66);
    *(undefined2 *)(iVar1 + 0x1aa) = 2;
    *(ushort *)(iVar1 + 0x66) = sVar6 - ((uVar3 & 0xff) - 0x80);
    *(undefined2 *)(param_1 + 500) = 0x78;
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) | 2;
  }
  sVar6 = *(short *)(param_1 + 500);
  if (sVar6 == 100) {
    if (DAT_800e1126 < 5) {
      iVar1 = func_0x80031ff0(0x27);
      iVar5 = *(int *)(param_1 + 0x234);
      *(undefined4 *)(iVar1 + 0x28) = *(undefined4 *)(iVar5 + 0x62c);
      *(undefined4 *)(iVar1 + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
      *(undefined4 *)(iVar1 + 0x30) = *(undefined4 *)(iVar5 + 0x634);
      uVar3 = func_0x80033604();
      sVar6 = *(short *)(param_1 + 0x66);
      *(undefined2 *)(iVar1 + 0x1aa) = 2;
      *(ushort *)(iVar1 + 0x66) = (sVar6 - (uVar3 & 0xff)) + 0x880;
    }
    sVar6 = *(short *)(param_1 + 500);
  }
  if (((sVar6 == 0x5a) && (DAT_800e1126 < 5)) &&
     (uVar2 = func_0x80033604(param_1,param_2), (uVar2 & 1) != 0)) {
    iVar1 = func_0x80031ff0(0x27);
    iVar5 = *(int *)(param_1 + 0x234);
    *(undefined4 *)(iVar1 + 0x28) = *(undefined4 *)(iVar5 + 0x62c);
    *(undefined4 *)(iVar1 + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
    *(undefined4 *)(iVar1 + 0x30) = *(undefined4 *)(iVar5 + 0x634);
    uVar3 = func_0x80033604();
    sVar6 = *(short *)(param_1 + 0x66);
    *(undefined2 *)(iVar1 + 0x1aa) = 2;
    *(ushort *)(iVar1 + 0x66) = (sVar6 - (uVar3 & 0xff)) + 0x480;
  }
  iVar1 = func_0x80089d54(param_1,param_2,param_3,0x40);
  if (iVar1 != 0) {
    *(undefined1 *)(param_1 + 0x1ea) = 0x3f;
    bVar4 = func_0x80033604();
    DAT_80167fca = '\x03' - bVar4 % 6;
    bVar4 = func_0x80033604();
    DAT_80167fcb = '\x0f' - bVar4 % 0x1e;
  }
  if ((*(short *)(param_1 + 500) < 0x3c) && ((*(ushort *)(param_1 + 500) & 0xf) == 0)) {
    iVar1 = *(int *)(param_1 + 0x234);
    uVar3 = func_0x80033604();
    local_20[0] = 0x80 - (uVar3 & 0xff);
    local_20[1] = 0;
    uVar3 = func_0x80033604();
    local_20[2] = 0x80 - (uVar3 & 0xff);
    func_0x80037780(0x151000,(int)*(short *)(param_1 + 0x66),iVar1 + 0x618,local_20);
  }
  sVar6 = *(short *)(param_1 + 500) + -1;
  *(short *)(param_1 + 500) = sVar6;
  if (sVar6 == -1) {
    *(undefined4 *)(param_1 + 4) = 0x1010000;
    *(byte *)(param_1 + 0x2be) = *(byte *)(param_1 + 0x2be) & 0x7f;
    uVar2 = func_0x80033604();
    uVar2 = (uVar2 & 0xff) + 300;
    *(short *)(param_1 + 0x2b4) = (short)uVar2;
    if (DAT_800e1126 < 4) {
      *(short *)(param_1 + 0x2b4) = (short)(uVar2 >> 1);
    }
    if ((*(uint *)(param_1 + 0x28c) < 4000) && (DAT_800e139f == '\0')) {
      *(undefined4 *)(param_1 + 4) = 0x1030000;
    }
  }
  return;
}

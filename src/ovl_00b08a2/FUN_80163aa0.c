/* FUN_80163aa0
 * image   ovl_00b08a2 (ovl), base 0x80161cf0
 * address 0x80163aa0  body 0x80163aa0..0x801640d7  size 1592 B
 * body sha256 2b1301726d4c48edb59e005269f490f18f6d751c8b6f6950bcf99ab2b8bd840b
 * provider record sha256 7ddf1e90dae91845cab0b1c9597bb272c18e33227f09732768b8b9ed38270dff
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80163aa0(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined2 uVar1;
  short sVar3;
  uint uVar2;
  ushort uVar4;
  uint *puVar5;
  int iVar6;
  undefined2 local_20;
  short local_1e;
  short local_1c;
  
  puVar5 = *(uint **)(param_1 + 0x234);
  switch(*(undefined1 *)(param_1 + 6)) {
  case 0:
    uVar2 = (uint)*(byte *)(param_1 + 0x2b4);
    *(undefined4 *)(param_1 + 0x1e8) = 0;
    *(undefined2 *)(param_1 + 100) = *(undefined2 *)(&DAT_801671ce + uVar2 * 0xc);
    *(undefined2 *)(param_1 + 0x66) = *(undefined2 *)(&DAT_801671d0 + uVar2 * 0xc);
    uVar1 = *(undefined2 *)(&DAT_801671d2 + uVar2 * 0xc);
    *(undefined2 *)(param_1 + 0x1f6) = 0x40;
    *(undefined1 *)(param_1 + 0x2b5) = 2;
    *(undefined1 *)(param_1 + 0x206) = 0;
    *(undefined2 *)(param_1 + 500) = 0;
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined2 *)(param_1 + 0x68) = uVar1;
    *(undefined2 *)(puVar5 + 0x49) = 0;
    *puVar5 = *puVar5 | 1;
    *(undefined4 *)(param_1 + 0x284) = 4;
    func_0x80077d18(0,param_1);
  case 1:
    func_0x80089d54(param_1,param_2,param_3,0x40);
    *(short *)(puVar5 + 0x49) = *(short *)(puVar5 + 0x49) + *(short *)(param_1 + 500);
    *(short *)(param_1 + 500) = *(short *)(param_1 + 500) + 8;
    if (0xc00 < *(short *)(puVar5 + 0x49)) {
      *(undefined1 *)(param_1 + 6) = 2;
      *(undefined4 *)(param_1 + 0x1e8) = 0x2001f00;
    }
    *(short *)(param_1 + 0x68) = *(short *)(param_1 + 0x68) - *(short *)(param_1 + 0x1f6);
    *(short *)(param_1 + 0x1f6) = *(short *)(param_1 + 0x1f6) + -4;
    break;
  case 2:
    func_0x80089d54(param_1,param_2,param_3,0x80);
    *(short *)(puVar5 + 0x49) = *(short *)(puVar5 + 0x49) + *(short *)(param_1 + 500);
    *(short *)(param_1 + 500) = *(short *)(param_1 + 500) + 0x10;
    if (0x1000 < *(short *)(puVar5 + 0x49)) {
      *(undefined2 *)(puVar5 + 0x49) = 0x1000;
      *(undefined1 *)(param_1 + 6) = 3;
      func_0x80077d18(0xf,param_1);
    }
  case 3:
    *(short *)(param_1 + 0x68) = *(short *)(param_1 + 0x68) - *(short *)(param_1 + 0x1f6);
    if (*(char *)(param_1 + 6) == '\x03') {
      *(short *)(param_1 + 0x1f6) = *(short *)(param_1 + 0x1f6) + -4;
    }
    FUN_80166510(param_1,*(undefined4 *)(param_1 + 0x234));
    iVar6 = *(int *)(param_1 + 0x234);
    local_20 = 0x5dc;
    local_1e = 0;
    local_1c = 0;
    func_0x8004276c(iVar6 + 0x4a0,&local_20,&local_20);
    uVar4 = local_1e + *(short *)(iVar6 + 0x4ba);
    local_1c = local_1c + *(short *)(iVar6 + 0x4be);
    if ((0 < (int)((uint)uVar4 << 0x10)) && (*(char *)(param_1 + 0x206) == '\0')) {
      *(undefined1 *)(param_1 + 6) = 4;
    }
    if (((short)uVar4 < -5000) && (*(char *)(param_1 + 0x206) == '\0')) {
      *(undefined1 *)(param_1 + 6) = 4;
    }
    if ((local_1c < -27000) && (*(char *)(param_1 + 0x206) == '\0')) {
      *(undefined1 *)(param_1 + 6) = 4;
    }
    if ((-0x4d58 < local_1c) && (*(char *)(param_1 + 0x206) == '\0')) {
      *(undefined1 *)(param_1 + 6) = 4;
    }
    break;
  case 4:
    *(undefined2 *)(param_1 + 0x1f6) = 0x40;
    *(undefined2 *)(param_1 + 500) = 0x3c;
    *(undefined1 *)(param_1 + 6) = 5;
    *(undefined1 *)(param_1 + 0x206) = 1;
    *(undefined1 *)(param_1 + 0x2b5) = 1;
    func_0x80077d18(2,param_1);
    *(undefined1 *)(param_1 + 0x2be) = 7;
  case 5:
    sVar3 = *(short *)(param_1 + 500) + -1;
    *(short *)(param_1 + 500) = sVar3;
    if (sVar3 == -1) {
      *(undefined1 *)(param_1 + 6) = 6;
      *(undefined4 *)(param_1 + 0x1e8) = 0x3f00;
      *(undefined2 *)(param_1 + 500) = 8;
      *(short *)(param_1 + 0x2b6) = *(short *)((int)puVar5 + 0x4b6) - *(short *)((int)puVar5 + 0x4e)
      ;
      *(undefined2 *)(param_1 + 0x2b8) = *(undefined2 *)(puVar5 + 0x49);
      *(undefined2 *)(param_1 + 0x2ba) = *(undefined2 *)((int)puVar5 + 0x4e);
    }
    *(short *)(puVar5 + 0x17) = *(short *)(puVar5 + 0x17) + *(short *)(param_1 + 0x1f6);
    *(short *)(puVar5 + 0x75) = *(short *)(puVar5 + 0x75) - *(short *)(param_1 + 0x1f6);
    *(short *)(puVar5 + 0xd3) = *(short *)(puVar5 + 0xd3) - *(short *)(param_1 + 0x1f6);
    *(short *)(puVar5 + 0x131) = *(short *)(puVar5 + 0x131) - (*(short *)(param_1 + 0x1f6) >> 1);
    sVar3 = *(short *)(param_1 + 0x1f6) + *(char *)(param_1 + 0x206) * -2;
    *(short *)(param_1 + 0x1f6) = sVar3;
    if (sVar3 == 0) {
      *(undefined2 *)(param_1 + 500) = 0;
    }
    FUN_80166598(param_1,*(undefined4 *)(param_1 + 0x234));
    iVar6 = *(int *)(param_1 + 0x234);
    if (((int)*(short *)(param_1 + 0x68) + (int)*(short *)(iVar6 + 0x5c) +
         (int)*(short *)(iVar6 + 0x1d4) + (int)*(short *)(iVar6 + 0x34c) +
         (int)*(short *)(iVar6 + 0x4c4) & 0xfffU) - 0x801 < 0x7ff) {
      *(short *)(iVar6 + 0x5c) = *(short *)(iVar6 + 0x5c) - *(short *)(param_1 + 0x1f6);
      *(short *)(iVar6 + 0x1d4) = *(short *)(iVar6 + 0x1d4) + *(short *)(param_1 + 0x1f6);
      *(short *)(iVar6 + 0x34c) = *(short *)(iVar6 + 0x34c) + *(short *)(param_1 + 0x1f6);
      *(short *)(iVar6 + 0x4c4) = *(short *)(iVar6 + 0x4c4) + (*(short *)(param_1 + 0x1f6) >> 1);
      FUN_80166598(param_1,*(undefined4 *)(param_1 + 0x234));
      *(undefined2 *)(param_1 + 0x1f6) = 0;
      *(undefined1 *)(param_1 + 0x206) = 0;
    }
    break;
  case 6:
    *(undefined2 *)(param_1 + 500) = 0;
    break;
  case 7:
    if (*(short *)(param_1 + 500) < 10) {
      *(short *)(puVar5 + 0x17) = *(short *)(puVar5 + 0x17) + *(short *)(param_1 + 500) * -2;
      *(short *)(puVar5 + 0x75) = *(short *)(puVar5 + 0x75) + *(short *)(param_1 + 500) * 2;
      *(short *)(puVar5 + 0xd3) = *(short *)(puVar5 + 0xd3) + *(short *)(param_1 + 500) * 2;
      *(short *)(puVar5 + 0x131) = *(short *)(puVar5 + 0x131) + *(short *)(param_1 + 500);
      FUN_80166598(param_1,*(undefined4 *)(param_1 + 0x234));
    }
    if (*(ushort *)(param_1 + 500) - 8 < 0xa7) {
      uVar2 = func_0x80033604();
      *(uint *)(param_1 + 0x28) =
           *(int *)(param_1 + 0x28) + (uVar2 & 0xf) * ((*(ushort *)(param_1 + 500) & 1) * -2 + 1);
      uVar2 = func_0x80033604();
      *(uint *)(param_1 + 0x2c) =
           *(int *)(param_1 + 0x2c) + (uVar2 & 0xf) * ((*(ushort *)(param_1 + 500) & 1) * -2 + 1);
      uVar2 = func_0x80033604();
      *(uint *)(param_1 + 0x30) =
           *(int *)(param_1 + 0x30) + (uVar2 & 0xf) * ((*(ushort *)(param_1 + 500) & 1) * -2 + 1);
    }
    if (0xa5 < *(short *)(param_1 + 500)) {
      *(short *)(puVar5 + 0x17) = *(short *)(puVar5 + 0x17) + 4;
      *(short *)(puVar5 + 0x75) = *(short *)(puVar5 + 0x75) + -4;
      *(short *)(puVar5 + 0xd3) = *(short *)(puVar5 + 0xd3) + -4;
      *(short *)(puVar5 + 0x131) = *(short *)(puVar5 + 0x131) + -2;
      FUN_80166598(param_1,*(undefined4 *)(param_1 + 0x234));
    }
    if (*(short *)(param_1 + 500) == 0xb4) {
      *(undefined1 *)(param_1 + 6) = 8;
    }
    *(short *)(param_1 + 500) = *(short *)(param_1 + 500) + 1;
    break;
  case 9:
    func_0x80089d54(param_1,param_2,param_3,0x40);
    *(short *)(puVar5 + 0x49) = *(short *)(puVar5 + 0x49) - *(short *)(param_1 + 500);
    *(short *)(param_1 + 500) = *(short *)(param_1 + 500) + 4;
    *(short *)(param_1 + 0x68) = *(short *)(param_1 + 0x68) + 8;
    if (*(short *)(puVar5 + 0x49) < 0) {
      *(undefined2 *)(puVar5 + 0x49) = 0;
      *(undefined1 *)(param_1 + 6) = 10;
      func_0x80077d18(0);
    }
  }
  return;
}

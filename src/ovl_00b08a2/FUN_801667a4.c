/* FUN_801667a4
 * image   ovl_00b08a2 (ovl), base 0x80161cf0
 * address 0x801667a4  body 0x801667a4..0x801668eb  size 328 B
 * body sha256 8a4f7e01e766a5879b832074d0b738d8a120888ddc0ea2db726783024647e298
 * provider record sha256 564492ae8c612bb31a12da35736698b79429e3f1f4241f7ae007dd5a30860ee8
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801667a4(int param_1)

{
  ushort uVar1;
  ushort uVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = *(int *)(param_1 + 0x234);
  *(undefined4 *)(param_1 + 0x120) = *(undefined4 *)(iVar4 + 0x1c4);
  *(undefined4 *)(param_1 + 0x124) = *(undefined4 *)(iVar4 + 0x1c8);
  *(undefined4 *)(param_1 + 0x128) = *(undefined4 *)(iVar4 + 0x1cc);
  *(undefined4 *)(param_1 + 0x140) = *(undefined4 *)(iVar4 + 0x4c);
  *(undefined4 *)(param_1 + 0x144) = *(undefined4 *)(iVar4 + 0x50);
  iVar5 = (uint)*(ushort *)(param_1 + 0x142) - (uint)*(ushort *)(param_1 + 0x122);
  *(undefined4 *)(param_1 + 0x148) = *(undefined4 *)(iVar4 + 0x54);
  uVar1 = *(short *)(param_1 + 0x146) - *(short *)(param_1 + 0x126);
  uVar2 = *(short *)(param_1 + 0x14a) - *(short *)(param_1 + 0x12a);
  *(int *)(param_1 + 0x160) = *(int *)(param_1 + 0x120) + (iVar5 * 0x10000 >> 0x12);
  *(int *)(param_1 + 0x164) = *(int *)(param_1 + 0x124) + ((int)((uint)uVar1 << 0x10) >> 0x12);
  *(int *)(param_1 + 0x168) = *(int *)(param_1 + 0x128) + ((int)((uint)uVar2 << 0x10) >> 0x12);
  *(int *)(param_1 + 0x180) = *(int *)(param_1 + 0x120) + (iVar5 * 0x10000 >> 0x11);
  *(int *)(param_1 + 0x184) = *(int *)(param_1 + 0x124) + ((int)((uint)uVar1 << 0x10) >> 0x11);
  *(undefined1 *)(param_1 + 0xd) = 0xff;
  *(int *)(param_1 + 0x188) = *(int *)(param_1 + 0x128) + ((int)((uint)uVar2 << 0x10) >> 0x11);
  *(ushort *)(param_1 + 700) = *(ushort *)(param_1 + 700) & 0xfff9;
  sVar3 = func_0x8004d3a0(0x800e1130,param_1);
  *(ushort *)(param_1 + 700) = *(ushort *)(param_1 + 700) | sVar3 << 1;
  return;
}

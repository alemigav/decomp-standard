/* FUN_801668ec
 * image   ovl_00b08a2 (ovl), base 0x80161cf0
 * address 0x801668ec  body 0x801668ec..0x80166a33  size 328 B
 * body sha256 6ca17873545f858afa8a5f9d41b90e08426d6a5990803a908873383c0850e99b
 * provider record sha256 5dc768ce805493dd38d8ce00a80b32d1b3d9ce6a087ad12d4cdfbd1ebe21ca40
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801668ec(int param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)((*(byte *)(param_1 + 0x2b4) - 1) * 4 + -0x7ff1ec18);
  iVar2 = *(int *)(iVar3 + 0x234);
  *(undefined4 *)(param_1 + 0x120) = *(undefined4 *)(iVar2 + 0x4b4);
  *(undefined4 *)(param_1 + 0x124) = *(undefined4 *)(iVar2 + 0x4b8);
  *(undefined4 *)(param_1 + 0x128) = *(undefined4 *)(iVar2 + 0x4bc);
  *(undefined4 *)(param_1 + 0x140) = *(undefined4 *)(iVar2 + 0x33c);
  *(undefined4 *)(param_1 + 0x144) = *(undefined4 *)(iVar2 + 0x340);
  *(undefined4 *)(param_1 + 0x148) = *(undefined4 *)(iVar2 + 0x344);
  *(undefined4 *)(param_1 + 0x160) = *(undefined4 *)(iVar2 + 0x1c4);
  *(undefined4 *)(param_1 + 0x164) = *(undefined4 *)(iVar2 + 0x1c8);
  *(undefined4 *)(param_1 + 0x168) = *(undefined4 *)(iVar2 + 0x1cc);
  *(int *)(param_1 + 0x180) =
       *(int *)(param_1 + 0x160) +
       ((int)(((uint)*(ushort *)(param_1 + 0x142) - (uint)*(ushort *)(param_1 + 0x162)) * 0x10000)
       >> 0x11);
  *(int *)(param_1 + 0x184) =
       *(int *)(param_1 + 0x164) +
       ((int)((uint)(ushort)(*(short *)(param_1 + 0x146) - *(short *)(param_1 + 0x166)) << 0x10) >>
       0x11);
  *(undefined1 *)(param_1 + 0xd) = 0xff;
  *(int *)(param_1 + 0x188) =
       *(int *)(param_1 + 0x168) +
       ((int)((uint)(ushort)(*(short *)(param_1 + 0x14a) - *(short *)(param_1 + 0x16a)) << 0x10) >>
       0x11);
  *(ushort *)(iVar3 + 700) = *(ushort *)(iVar3 + 700) & 0xfff9;
  sVar1 = func_0x8004d3a0(param_1,0x800e1130);
  *(ushort *)(iVar3 + 700) = *(ushort *)(iVar3 + 700) | sVar1 * 6;
  return;
}

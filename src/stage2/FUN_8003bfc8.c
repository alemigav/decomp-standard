/* FUN_8003bfc8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003bfc8  body 0x8003bfc8..0x8003c113  size 332 B
 * body sha256 6826d7933325cb77a62f4e96e1f6a8c18c71d2d64072eacb7b5a0fe4374f11cf
 * provider record sha256 04f3b147d4e24ee6e96c499396ea7173b6806ddf9690b8d70923cc20d18d760c
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003bfc8(void)

{
  undefined2 *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = FUN_80033604();
  *(ushort *)(DAT_800ebb94 + 0xc) =
       (short)*(char *)(DAT_800ebb94 + 0x43) *
       (((short)(uVar3 & 0xff) + (short)((uVar3 & 0xff) / 0x46) * -0x46 & 0xffU) + 0x32);
  uVar3 = FUN_80033604();
  *(short *)(DAT_800ebb94 + 0x10) =
       (short)*(char *)(DAT_800ebb94 + 0x43) * (short)((uVar3 & 0xff) % 0x32);
  uVar3 = FUN_80033604();
  iVar2 = DAT_800ebb94;
  puVar1 = (undefined2 *)(DAT_800ebb94 + 0x40);
  *(short *)(DAT_800ebb94 + 0x42) = (short)-*(char *)(DAT_800ebb94 + 0x43);
  *(undefined2 *)(iVar2 + 0x38) = *puVar1;
  iVar4 = (uVar3 & 0xff) % 0x14 + 0x28;
  *(short *)(iVar2 + 0xe) = (short)iVar4;
  *(undefined4 *)(iVar2 + 0x34) = *(undefined4 *)(iVar2 + 0x3c);
  *(short *)(iVar2 + 0x4a) = (short)((iVar4 * -3) / 10);
  return;
}

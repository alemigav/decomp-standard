/* FUN_8003f978
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003f978  body 0x8003f978..0x8003fa9f  size 296 B
 * body sha256 46f83c2d1c353b2231b7ac1dc9fcadcbfa2ada09f9677b8252a6c6481046af23
 * provider record sha256 bda60675a743ab7f02b3c2aec97b0dfa0200a75e4d0866ef6df9c504d631c74b
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003f978(void)

{
  byte bVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  
  FUN_80039ba8();
  iVar4 = DAT_800ebb94;
  sVar2 = *(short *)(DAT_800ebb94 + 0x22);
  uVar5 = *(undefined4 *)(DAT_800ebb94 + 0x6c);
  bVar1 = *(byte *)(DAT_800ebb94 + 0x1c);
  iVar6 = DAT_800ebb94 + 0x2c;
  *(undefined2 *)(DAT_800ebb94 + 0x46) = 0x800;
  *(undefined2 *)(iVar4 + 0x48) = 0x82;
  uVar3 = FUN_80038a20((uint)bVar1 << 0x18 | (uint)*(byte *)(iVar4 + 0x1e) << 0x10 |
                       (uint)*(ushort *)(iVar4 + 0x3a),(int)sVar2,uVar5,iVar6);
  if ((uVar3 & 0xff) < 0xff) {
    iVar4 = (uVar3 & 0xff) * 0x7c;
    (&DAT_800ebda8)[iVar4] = 1;
    (&DAT_800ebdc3)[iVar4] = 1;
    *(undefined2 *)(&DAT_800ebdec + iVar4) = 0x400;
    *(undefined2 *)(&DAT_800ebdee + iVar4) = 0x768;
    *(undefined2 *)(&DAT_800ebdf0 + iVar4) = 0xfc4;
  }
  uVar3 = FUN_80038a20((uint)*(byte *)(DAT_800ebb94 + 0x1c) << 0x18 |
                       (uint)*(byte *)(DAT_800ebb94 + 0x1e) << 0x10 |
                       (uint)*(ushort *)(DAT_800ebb94 + 0x3a),(int)*(short *)(DAT_800ebb94 + 0x22),
                       *(undefined4 *)(DAT_800ebb94 + 0x6c),DAT_800ebb94 + 0x2c);
  if ((uVar3 & 0xff) < 0xff) {
    iVar4 = (uVar3 & 0xff) * 0x7c;
    (&DAT_800ebda8)[iVar4] = 1;
    (&DAT_800ebdc3)[iVar4] = 2;
    *(undefined2 *)(&DAT_800ebdec + iVar4) = 0xc00;
    *(undefined2 *)(&DAT_800ebdee + iVar4) = 0x898;
    *(undefined2 *)(&DAT_800ebdf0 + iVar4) = 0xfc4;
  }
  return;
}

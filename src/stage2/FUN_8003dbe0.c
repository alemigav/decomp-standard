/* FUN_8003dbe0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003dbe0  body 0x8003dbe0..0x8003dd1b  size 316 B
 * body sha256 a5744f566157945c7a0e48a827e06fc0a7f1daeacfa092ed889a9aa0372a06fd
 * provider record sha256 bde91bae41700de54d325cd53003b979e432efab5f6789761d8edacd3ea9c5fc
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003dbe0(void)

{
  undefined1 *puVar1;
  uint uVar2;
  int iVar3;
  undefined2 uVar4;
  int iVar5;
  undefined2 local_30;
  short local_2e;
  undefined2 local_2c;
  
  DAT_80131781 = 1;
  local_30 = *(undefined2 *)(DAT_800ebb94 + 0x2c);
  iVar5 = 0x13;
  local_2e = *(short *)(DAT_800ebb94 + 0x2e);
  local_2c = *(undefined2 *)(DAT_800ebb94 + 0x30);
  do {
    iVar5 = iVar5 + -1;
    uVar2 = FUN_80038a20(0x6042000,(int)*(short *)(DAT_800ebb94 + 0x22),DAT_800ebb94 + 0x4c,
                         &local_30);
    if ((uVar2 & 0xff) < 0xff) {
      iVar3 = (uVar2 & 0xff) * 0x7c;
      uVar2 = FUN_80033604();
      *(short *)(&DAT_800ebdee + iVar3) = (short)((uVar2 & 0xff) % 0x32) * 0x28 + -1000;
      uVar2 = FUN_80033604();
      uVar4 = 0xc00;
      if ((uVar2 & 2) != 0) {
        uVar4 = 0x400;
      }
      *(undefined2 *)(&DAT_800ebdf0 + iVar3) = uVar4;
    }
    else {
      iVar5 = 0;
    }
    puVar1 = DAT_800ebb94;
    local_2e = local_2e + 0x1b0;
  } while (iVar5 != 0);
  DAT_800ebb94[1] = 0;
  *puVar1 = 0;
  *(undefined2 *)(puVar1 + 0x18) = 0;
  return;
}

/* FUN_800716b0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800716b0  body 0x800716b0..0x80071743  size 148 B
 * body sha256 ed92bfa96208772a13bafec5e3d18a0d1e496f976f7ba68d5926612640a7f4ee
 * provider record sha256 92c19516ab056191b923bee119d9acac055de0d87f43f8cec28f7029656d7f23
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_800716b0(int param_1)

{
  char cVar1;
  int iVar2;
  undefined1 *puVar3;
  uint uVar4;
  
  cVar1 = *(char *)(*(int *)(param_1 + 0x1c) + 1);
  if (cVar1 == '\x06') {
    FUN_80038ff0();
  }
  else {
    iVar2 = FUN_800717a0((int)cVar1,(int)*(char *)(*(int *)(param_1 + 0x1c) + 2));
    uVar4 = 0;
    puVar3 = &DAT_800ebda8;
    do {
      uVar4 = uVar4 + 1;
      if (*(int *)(puVar3 + 0x6c) == iVar2) {
        puVar3[1] = 0;
        *puVar3 = 0;
        *(undefined2 *)(puVar3 + 0x18) = 0;
      }
      puVar3 = puVar3 + 0x7c;
    } while (uVar4 < 0x60);
  }
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 3;
  return 1;
}

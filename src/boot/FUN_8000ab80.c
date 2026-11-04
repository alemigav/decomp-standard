/* FUN_8000ab80
 * image   boot (boot), base 0x80000480
 * address 0x8000ab80  body 0x8000ab80..0x8000abff  size 128 B
 * body sha256 97eb8ca4f3676838ebcfc50dfe9d17544c825b0f893885570673ea7b765a3549
 * provider record sha256 21f014e387c891c1d0143e53c6a67aaf645f953f7f0eb40480d0b95622366ea7
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8000ab80(int param_1,undefined2 *param_2)

{
  undefined1 uVar1;
  undefined1 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  undefined1 uStack_d;
  
  puVar6 = (uint *)&DAT_80016470;
  iVar5 = 0;
  if (0 < param_1) {
    do {
      iVar5 = iVar5 + 1;
      puVar6 = (uint *)((int)puVar6 + 1);
    } while (iVar5 < param_1);
  }
  uVar3 = *puVar6;
  uVar1 = *(undefined1 *)(puVar6 + 1);
  uVar2 = *(undefined1 *)((int)puVar6 + 5);
  uVar4 = (uVar3 >> 0x10 & 0xc0) >> 4;
  *(char *)((int)param_2 + 3) = (char)uVar4;
  if (uVar4 == 0) {
    uStack_d = (undefined1)uVar3;
    *param_2 = CONCAT11(uVar1,uStack_d);
    *(undefined1 *)(param_2 + 1) = uVar2;
  }
  return;
}

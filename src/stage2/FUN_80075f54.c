/* FUN_80075f54
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80075f54  body 0x80075f54..0x80075fbf  size 108 B
 * body sha256 ab9c7a8717f94b87502ddd2d22211ebd85df35bbe2f0ac707eff21f931b7a415
 * provider record sha256 39da0c742f89a884e1d19eb83edd1f8482bd74e1b9ff4b7063b5885dae0229e9
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80075f54(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  
  iVar5 = 0;
  puVar4 = (undefined4 *)&DAT_8011a37c;
  do {
    uVar2 = 0;
    *(undefined1 *)(puVar4 + 10) = 0;
    *(undefined2 *)((int)puVar4 + 2) = 0;
    *(undefined2 *)puVar4 = 0;
    iVar3 = iVar5;
    do {
      iVar1 = uVar2 + iVar5;
      uVar2 = uVar2 + 1;
      *(undefined4 *)((int)&DAT_8011a380 + iVar3) = 0xffffffff;
      *(undefined4 *)((int)&DAT_8011a390 + iVar3) = 0;
      (&DAT_8011a3a0)[iVar1] = 0;
      iVar3 = iVar3 + 4;
    } while (uVar2 < 4);
    puVar4 = puVar4 + 0xf;
    iVar5 = iVar5 + 0x3c;
  } while (puVar4 < &DAT_8011a700);
  return;
}

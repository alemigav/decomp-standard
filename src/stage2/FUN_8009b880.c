/* FUN_8009b880
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009b880  body 0x8009b880..0x8009b977  size 248 B
 * body sha256 d842842cc986cdacbfca5525fae470486c1cc87935c0e3035c7128c3ada37c19
 * provider record sha256 9292ec4b8355f4ce8e09ba839c8c165f82e0f71d7cef13c5e2c3195d43aa0ab0
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8009b880(void)

{
  int iVar1;
  undefined *puVar2;
  uint uVar3;
  
  uVar3 = 10;
  puVar2 = &DAT_80114958;
  DAT_80114f34 = 1;
  DAT_80114f2c = DAT_800c52dc + 0x3b800;
  do {
    if (puVar2[1] != '\0') {
      while( true ) {
        do {
          iVar1 = (*(code *)(&PTR_LAB_80113898)[**(byte **)(puVar2 + 0x1c)])(puVar2);
        } while (iVar1 == 1);
        if ((iVar1 == 2) || ((char)puVar2[(char)puVar2[2] + 4] < '\0')) break;
        iVar1 = *(int *)(puVar2 + 0x140);
        *(int *)(puVar2 + 0x140) = iVar1 + -4;
        *(undefined4 *)(puVar2 + 0x1c) = *(undefined4 *)(iVar1 + -4);
        puVar2[(char)puVar2[2] + 4] = puVar2[(char)puVar2[2] + 4] + -1;
      }
    }
    uVar3 = uVar3 + 1;
    puVar2 = puVar2 + 0x174;
  } while (uVar3 < 0xe);
  return;
}

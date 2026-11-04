/* FUN_800850e0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800850e0  body 0x800850e0..0x80085163  size 132 B
 * body sha256 462e0a0cfa6f457c5be92f4257be84766e0c687389f864e9e50b30578e21e22a
 * provider record sha256 4402fd81dd2840b77e9204ebeb8f686454a9e0f96d4e87556ba51dc1e61109bf
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800850e0(void)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar2 = 0;
  iVar1 = 0;
  do {
    iVar2 = iVar2 + 1;
    *(undefined4 *)((int)&DAT_8012487c + iVar1) = 0;
    *(int *)((int)&DAT_80124880 + iVar1) = iVar2;
    *(undefined4 *)((int)&DAT_80124884 + iVar1) = 0;
    iVar1 = iVar2 * 0x10;
  } while (iVar2 < 0x80);
  iVar1 = 1;
  puVar3 = &DAT_8012485c;
  DAT_80124880 = 0;
  DAT_8012486c = 1;
  do {
    puVar3[5] = 0;
    iVar1 = iVar1 + 1;
    puVar3 = puVar3 + 1;
  } while (iVar1 < 4);
  DAT_80124868 = 0;
  DAT_80125070 = 0;
  DAT_80124858 = 0;
  DAT_8012485c = 1;
  return;
}

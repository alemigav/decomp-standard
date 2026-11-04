/* FUN_80035b84
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80035b84  body 0x80035b84..0x80035c07  size 132 B
 * body sha256 07e56cabde91694cd337ee1deb49d16b0cad1747fcc5c67a1326b0221d746a92
 * provider record sha256 18cd8267e4e08d851c38d931e30ad2019438dc66970329d1b2e23b5fa9b7aa77
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80035b84(int param_1)

{
  undefined *puVar1;
  undefined1 uVar2;
  
  if (DAT_800e8ca8 < 3) {
    if ((DAT_800e110c & 0x2000000) == 0) {
      uVar2 = *(undefined1 *)(param_1 + 0x26a);
      puVar1 = &DAT_800e8d08;
    }
    else {
      uVar2 = *(undefined1 *)(param_1 + 0x26a);
      puVar1 = &DAT_800e8d28;
    }
  }
  else {
    uVar2 = *(undefined1 *)(param_1 + 0x26a);
    puVar1 = &DAT_800e8d28;
  }
  FUN_80083758(puVar1,uVar2);
  return;
}

/* FUN_8007c2f0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007c2f0  body 0x8007c2f0..0x8007c3df  size 240 B
 * body sha256 0f07cd2acddb92f38b5250fe0cc5d28733e71cc5ff7a843566964ab5b1dfbec0
 * provider record sha256 2433971946323d173ae747ab09a4069b953b427c926c34615d4375a57a1ffc67
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007c2f0(int param_1,uint param_2)

{
  uint *puVar1;
  ushort uVar2;
  
  if (*(char *)(param_1 + 0x2c6) == '\0') {
    puVar1 = DAT_8011b54c;
    if ((param_2 & 0xf) == 10) {
      puVar1 = (uint *)FUN_80080c68(param_1);
      if (puVar1 == (uint *)0x0) {
        return;
      }
      if ((*(short *)((int)puVar1 + 0x1f2) < 0) ||
         ((*(ushort *)((int)puVar1 + 0x1aa) & 0x2000) != 0)) {
        puVar1 = (uint *)FUN_80080d64(param_1);
      }
    }
    if ((puVar1 != (uint *)0x0) && (-1 < *(short *)((int)puVar1 + 0x1f2))) {
      if ((*(ushort *)((int)puVar1 + 0x1aa) & 0x2000) == 0) {
        *(undefined4 *)(param_1 + 4) = 0x1050000;
        *(uint **)(param_1 + 0x250) = puVar1;
        uVar2 = *(ushort *)(param_1 + 0x1f0) & 0x1fff | 0x4000;
      }
      else {
        if ((*(ushort *)((int)puVar1 + 0x1aa) & 1) == 0) {
          return;
        }
        if ((*puVar1 & 0x4000000) == 0) {
          return;
        }
        *(undefined4 *)(param_1 + 4) = 0x1050000;
        *(uint **)(param_1 + 0x250) = puVar1;
        uVar2 = *(ushort *)(param_1 + 0x1f0) & 0x1fff | 0x2000;
      }
      *(ushort *)(param_1 + 0x1f0) = uVar2;
    }
  }
  return;
}

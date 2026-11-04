/* FUN_800abad4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800abad4  body 0x800abad4..0x800ac0c7  size 1524 B
 * body sha256 3765a8c101e509b445b6e31838fae4a7938e8021dad4b86bb9588a994c811ec1
 * provider record sha256 0534e0bf61e2aa0bce1b652033b4c302b8ef2fd5ac61caf0cfc95f23baf1a2c0
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800abad4(byte param_1,byte param_2)

{
  int iVar1;
  uint uVar2;
  
  if (param_2 == 0xff) {
    uVar2 = 0;
    iVar1 = (uint)param_1 * 0x86;
    do {
      *(undefined1 *)(iVar1 + -0x7feb3080) = 0;
      uVar2 = uVar2 + 1;
      iVar1 = uVar2 + (uint)param_1 * 0x86;
    } while (uVar2 < 0x86);
  }
  else {
    uVar2 = 0;
    iVar1 = (uint)param_1 * 0x86;
    do {
      *(undefined1 *)(iVar1 + (uint)param_2 * 0x860 + -0x7feb7380) = 0;
      uVar2 = uVar2 + 1;
      iVar1 = uVar2 + (uint)param_1 * 0x86;
    } while (uVar2 < 0x86);
  }
  if (param_2 == 0xff) {
    *(undefined1 *)((uint)param_1 * 0x86 + -0x7feb3079) = 0x7f;
  }
  else {
    *(undefined1 *)((uint)param_1 * 0x86 + (uint)param_2 * 0x860 + -0x7feb7379) = 0x7f;
  }
  if (param_2 == 0xff) {
    *(undefined1 *)((uint)param_1 * 0x86 + -0x7feb3076) = 0x40;
  }
  else {
    *(undefined1 *)((uint)param_1 * 0x86 + (uint)param_2 * 0x860 + -0x7feb7376) = 0x40;
  }
  if (param_2 == 0xff) {
    *(undefined1 *)((uint)param_1 * 0x86 + -0x7feb3000) = 0x40;
  }
  else {
    *(undefined1 *)((uint)param_1 * 0x86 + (uint)param_2 * 0x860 + -0x7feb7300) = 0x40;
  }
  if (param_2 == 0xff) {
    *(undefined1 *)((uint)param_1 * 0x86 + -0x7feb2fff) = 0;
  }
  else {
    *(undefined1 *)((uint)param_1 * 0x86 + (uint)param_2 * 0x860 + -0x7feb72ff) = 0;
  }
  if (param_2 == 0xff) {
    *(undefined1 *)((uint)param_1 * 0x86 + -0x7feb3040) = 0;
  }
  else {
    *(undefined1 *)((uint)param_1 * 0x86 + (uint)param_2 * 0x860 + -0x7feb7340) = 0;
  }
  if (param_2 == 0xff) {
    *(undefined1 *)((uint)param_1 * 0x86 + -0x7feb303f) = 0;
  }
  else {
    *(undefined1 *)((uint)param_1 * 0x86 + (uint)param_2 * 0x860 + -0x7feb733f) = 0;
  }
  if (param_2 == 0xff) {
    *(undefined1 *)((uint)param_1 * 0x86 + -0x7feb3025) = 0;
  }
  else {
    *(undefined1 *)((uint)param_1 * 0x86 + (uint)param_2 * 0x860 + -0x7feb7325) = 0;
  }
  if (param_2 == 0xff) {
    *(undefined1 *)((uint)param_1 * 0x86 + -0x7feb2ffd) = 0;
  }
  else {
    *(undefined1 *)((uint)param_1 * 0x86 + (uint)param_2 * 0x860 + -0x7feb72fd) = 0;
  }
  if (param_2 == 0xff) {
    *(undefined1 *)((uint)param_1 * 0x86 + -0x7feb2ffc) = 0x40;
  }
  else {
    *(undefined1 *)((uint)param_1 * 0x86 + (uint)param_2 * 0x860 + -0x7feb72fc) = 0x40;
  }
  if (param_2 == 0xff) {
    *(undefined1 *)((uint)param_1 * 0x86 + -0x7feb2ffb) = 0;
  }
  else {
    *(undefined1 *)((uint)param_1 * 0x86 + (uint)param_2 * 0x860 + -0x7feb72fb) = 0;
  }
  FUN_800ac69c(param_1,param_2,0xff);
  FUN_800ac734(param_1,param_2,0);
  return;
}

/* FUN_80162190
 * image   ovl_00a0344 (ovl), base 0x80161cf0
 * address 0x80162190  body 0x80162190..0x80162223  size 148 B
 * body sha256 5ab233538cbb93c59584823b6c4f79cb9ea339d0f516670b48e714f100a2682a
 * provider record sha256 eb135823f364625074e4627ca1b6891ecef0b6a33e42f8bbe6a71df475cd5507
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80162190(int param_1)

{
  int iVar1;
  
  (*(code *)(&PTR_FUN_80163d9c)[*(byte *)(param_1 + 6)])();
  if (*(char *)(*(int *)(param_1 + 0x250) + 0x2b4) == '\0') {
    iVar1 = -0x7ff1eed0;
  }
  else {
    iVar1 = _DAT_800e13ec;
  }
  if ((*(byte *)(iVar1 + 0x26f) & 0x80) != 0) {
    *(undefined1 *)(param_1 + 0x2c5) = 1;
  }
  FUN_8016375c(param_1,0);
  return;
}

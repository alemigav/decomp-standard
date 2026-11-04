/* FUN_800a231c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a231c  body 0x800a231c..0x800a23cb  size 176 B
 * body sha256 5ad06a6afe0b1d8a6c6dca70d3282e24ac971777591a5347dfb0173e54731dde
 * provider record sha256 43095aeb778a15832c943fa80788ca31c24f265303d092ad92073ab5b3bf1d6c
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800a231c(uint param_1,uint param_2,undefined1 param_3)

{
  uint *puVar1;
  uint uVar2;
  
  if (DAT_80136310 != '\0') {
    uVar2 = 0;
    puVar1 = (uint *)&DAT_8013bc90;
    do {
      if ((*(char *)((int)puVar1 + 0xfc1) == '\0') && (*puVar1 == (param_1 & 0x7fffffff))) {
        uVar2 = uVar2 | param_1 & 0x80000000;
        goto LAB_800a2384;
      }
      uVar2 = uVar2 + 1;
      puVar1 = puVar1 + 0x3fe;
    } while (uVar2 < 8);
    uVar2 = 0xffffffff;
LAB_800a2384:
    if (uVar2 != 0xffffffff) {
      *(undefined1 *)((param_2 & 0xff) + uVar2 * 0xff8 + -0x7fec3e48) = param_3;
      FUN_800a832c(param_3,2);
    }
  }
  return;
}

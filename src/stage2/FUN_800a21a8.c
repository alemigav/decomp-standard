/* FUN_800a21a8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a21a8  body 0x800a21a8..0x800a2217  size 112 B
 * body sha256 00d99723dcbb2373975c44f61957ec6e1e1a61f85a7ae399ddb9e460b819db48
 * provider record sha256 e331a8651c14ccb28d347c20d93daaa907bc58d44aab35afb209564936148d4f
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
bool FUN_800a21a8(uint param_1)

{
  uint *puVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (DAT_80136310 == '\0') {
    return false;
  }
  puVar1 = (uint *)&DAT_8013bc90;
  while ((*(char *)((int)puVar1 + 0xfc1) != '\0' || (*puVar1 != (param_1 & 0x7fffffff)))) {
    uVar2 = uVar2 + 1;
    puVar1 = puVar1 + 0x3fe;
    if (7 < uVar2) {
      uVar2 = 0xffffffff;
LAB_800a21f8:
      return uVar2 != 0xffffffff;
    }
  }
  uVar2 = uVar2 | param_1 & 0x80000000;
  goto LAB_800a21f8;
}

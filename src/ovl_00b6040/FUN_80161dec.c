/* FUN_80161dec
 * image   ovl_00b6040 (ovl), base 0x80161cf0
 * address 0x80161dec  body 0x80161dec..0x80161f7b  size 400 B
 * body sha256 a014bb424329b6ce4dcf0093e3533d5ad8dbe3f8d34a2dbbb046cb021007ebdf
 * provider record sha256 d08ee10f5965713f67e601122e8e24f109d8fe9e1d8309c6de65c9997bacd8e6
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80161dec(int param_1)

{
  int iVar1;
  
  if (*(char *)(param_1 + 5) == '\0') {
    *(undefined4 *)(param_1 + 0x1e8) = 0;
    *(char *)(param_1 + 5) = *(char *)(param_1 + 5) + '\x01';
  }
  else if (*(char *)(param_1 + 5) != '\x01') {
    return;
  }
  iVar1 = *(int *)(param_1 + 0x234);
  if (*(byte *)(param_1 + 0x1e9) < 10) {
    *(int *)(iVar1 + 0x198) = *(int *)(iVar1 + 0x198) + 0xb;
  }
  if (*(byte *)(param_1 + 0x1e9) - 10 < 0xd) {
    *(int *)(iVar1 + 0x198) = *(int *)(iVar1 + 0x198) + 0xc;
  }
  if (*(byte *)(param_1 + 0x1e9) - 0x17 < 7) {
    *(int *)(iVar1 + 0x198) = *(int *)(iVar1 + 0x198) + 0xb;
  }
  if (*(char *)(param_1 + 0x1e9) == '(') {
    *(int *)(iVar1 + 0x310) = *(int *)(iVar1 + 0x310) + -0xc;
  }
  if (*(byte *)(param_1 + 0x1e9) - 0x29 < 7) {
    *(int *)(iVar1 + 0x310) = *(int *)(iVar1 + 0x310) + -0xd;
  }
  if (*(byte *)(param_1 + 0x1e9) - 0x2f < 7) {
    *(int *)(iVar1 + 0x600) = *(int *)(iVar1 + 0x600) + 0xc;
    *(int *)(iVar1 + 0x8f0) = *(int *)(iVar1 + 0x8f0) + 0xc;
    *(int *)(iVar1 + 0xbe0) = *(int *)(iVar1 + 0xbe0) + 0xc;
    *(int *)(iVar1 + 0xed0) = *(int *)(iVar1 + 0xed0) + 0xc;
  }
  if (*(byte *)(param_1 + 0x1e9) - 0x36 < 6) {
    *(int *)(iVar1 + 0x600) = *(int *)(iVar1 + 0x600) + 0xb;
    *(int *)(iVar1 + 0x8f0) = *(int *)(iVar1 + 0x8f0) + 0xb;
    *(int *)(iVar1 + 0xbe0) = *(int *)(iVar1 + 0xbe0) + 0xb;
    *(int *)(iVar1 + 0xed0) = *(int *)(iVar1 + 0xed0) + 0xb;
  }
  iVar1 = func_0x80089d54(param_1,*(undefined4 *)(param_1 + 0x1a4),*(undefined4 *)(param_1 + 0x218),
                          0);
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 4) = 0x2000000;
  }
  return;
}

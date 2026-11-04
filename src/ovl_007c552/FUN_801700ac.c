/* FUN_801700ac
 * image   ovl_007c552 (ovl), base 0x8016e880
 * address 0x801700ac  body 0x801700ac..0x80170103  size 88 B
 * body sha256 ba7723bdfd3b745b4d05c67356c90f6ad345a86f7d5218d70ea61dc787a891a7
 * provider record sha256 897d80f29a71202f9a3597007ec60a608b589ebdf8b3237621d1b163b775595c
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801700ac(uint param_1,undefined1 param_2,char param_3)

{
  undefined1 *puVar1;
  uint uVar2;
  
  puVar1 = &DAT_80171aac;
  uVar2 = 0;
  do {
    if ((param_1 >> (uVar2 & 0x1f) & 1) == 0) {
      if (param_3 != '\0') {
        *puVar1 = 0;
      }
    }
    else {
      *puVar1 = param_2;
    }
    if ((puVar1[1] & 0x20) != 0) {
      *puVar1 = 0;
    }
    uVar2 = uVar2 + 1;
    puVar1 = puVar1 + 0xc;
  } while (uVar2 < 0x1f);
  return;
}

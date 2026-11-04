/* FUN_8016358c
 * image   ovl_0097e42 (ovl), base 0x80161cf0
 * address 0x8016358c  body 0x8016358c..0x80163637  size 172 B
 * body sha256 8e29552035a6cef05f43105e016c2be153320191256ce2a8b503002caa106800
 * provider record sha256 283e8353495e56e7b3e75a79d710379d285e37f8c75c237e450af4716205f838
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_8016358c(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = 0;
  do {
    uVar1 = func_0x80033604();
    uVar1 = (uVar1 & 0xff) >> 3;
    uVar2 = 1 << uVar1;
    uVar3 = uVar3 + 1;
    if ((DAT_80163b00 & uVar2) == 0) {
      DAT_80163b00 = DAT_80163b00 | uVar2;
      return uVar1;
    }
    uVar1 = 1;
  } while (uVar3 < 0x20);
  uVar3 = 0;
  do {
    if ((DAT_80163b00 & uVar1) == 0) {
      DAT_80163b00 = DAT_80163b00 | uVar3;
      return uVar3;
    }
    uVar3 = uVar3 + 1;
    uVar1 = uVar1 << 1;
  } while (uVar3 < 0x20);
  return 0;
}

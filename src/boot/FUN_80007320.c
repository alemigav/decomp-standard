/* FUN_80007320
 * image   boot (boot), base 0x80000480
 * address 0x80007320  body 0x80007320..0x800073cf  size 176 B
 * body sha256 ff41bea0c0fd8cc12903c2a8bd8c421653fa9aa8b842d5359ce9432db150fba5
 * provider record sha256 19e8dff19cd68912c04649210ea5632d592924fc19a5571aa964c4604c47f3b2
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80007320(uint param_1,uint param_2)

{
  bool bVar1;
  undefined *puVar2;
  uint uVar3;
  
  if (0 < (int)param_2) {
    if (0x1fff < param_2) {
      puVar2 = (undefined *)0x80000000;
      do {
        cacheOp(1,puVar2);
        bVar1 = puVar2 < &UNK_80001ff0;
        puVar2 = puVar2 + 0x10;
      } while (bVar1);
      return;
    }
    if (param_1 < param_1 + param_2) {
      uVar3 = (param_1 + param_2) - 0x10;
      if ((param_1 & 0xf) != 0) {
        param_1 = param_1 - (param_1 & 0xf);
        cacheOp(0x15,param_1);
        if (uVar3 <= param_1) {
          return;
        }
        param_1 = param_1 + 0x10;
      }
      if ((uVar3 & 0xf) != 0) {
        uVar3 = uVar3 - (uVar3 & 0xf);
        cacheOp(0x15,uVar3 + 0x10);
        if (uVar3 < param_1) {
          return;
        }
      }
      do {
        cacheOp(0x11,param_1);
        bVar1 = param_1 < uVar3;
        param_1 = param_1 + 0x10;
      } while (bVar1);
    }
  }
  return;
}

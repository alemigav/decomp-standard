/* FUN_80082308
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80082308  body 0x80082308..0x80082387  size 128 B
 * body sha256 b0cca57094c44512679e72bb2c46fdd4f880a150dd137b7022d8d29bf075dfd5
 * provider record sha256 ce9c35edcd9b49b58986790b6a5498cb5214680b0c06ef4e171889abdd01007d
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_80082308(byte *param_1,byte *param_2)

{
  byte bVar1;
  uint uVar2;
  
  uVar2 = (uint)*param_1 - (uint)*param_2;
  if (uVar2 == 0) {
    if (*param_1 != 0) {
      do {
        bVar1 = *param_2;
        if (bVar1 == 0) break;
        param_2 = param_2 + 1;
        uVar2 = (uint)*param_1 - (uint)bVar1;
        param_1 = param_1 + 1;
        if (uVar2 != 0) {
          return uVar2;
        }
        uVar2 = 0;
      } while (*param_1 != 0);
    }
    if (((uVar2 == 0) && (uVar2 = (uint)*param_1, uVar2 == 0)) &&
       (uVar2 = -(uint)*param_2, *param_2 == 0)) {
      return 0;
    }
  }
  return uVar2;
}

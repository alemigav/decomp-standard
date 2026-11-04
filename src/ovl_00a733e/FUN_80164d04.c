/* FUN_80164d04
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x80164d04  body 0x80164d04..0x80164d9b  size 152 B
 * body sha256 b25d85a747d60a099fd91c97611c07ba3379fb5ea9eadf045e4194262a563c67
 * provider record sha256 4420dad4baa7b50ecbe6a88148ccf77cc4034f52ab1eac58c10abf297b8764a5
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_80164d04(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  undefined *puVar3;
  
  uVar1 = func_0x8006568c((int)_DAT_800e115a,(int)_DAT_800e1162);
  uVar2 = func_0x8006568c((int)*(short *)(param_1 + 0x2a),(int)*(short *)(param_1 + 0x32));
  if (param_2 == 0) {
    puVar3 = &UNK_80167e58;
  }
  else {
    puVar3 = &UNK_80167ed1;
  }
  return (int)(char)puVar3[(uVar1 & 0xff) + (uVar2 & 0xff) * 0xb];
}

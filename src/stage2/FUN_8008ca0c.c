/* FUN_8008ca0c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008ca0c  body 0x8008ca0c..0x8008cb47  size 316 B
 * body sha256 0f664fd80ee371136f1e3e0586651cd31e65937e730ff57b6d91adef00decb30
 * provider record sha256 a42bae7dbaf38f2b33059a30a71ba120f09cd68a89c261e8bdf27589f4137463
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008ca0c(uint param_1,int param_2,int param_3)

{
  short local_20;
  short local_1e;
  undefined2 local_1c;
  undefined2 local_1a;
  
  if ((DAT_800e110c & 0x8000) != 0) {
    local_1c = 0x28;
    local_1a = 0x1e;
    local_20 = (short)(param_1 % 3) * 0x28;
    local_1e = (short)(param_1 / 3) * 0x1e;
    FUN_80047b74(&DAT_8012f54c,&local_20);
    if (param_2 - 0xeU < 6) {
      local_20 = (short)((param_1 + 1) % 3) * 0x28;
      local_1e = (short)((param_1 + 1) / 3) * 0x1e;
      FUN_80047b74(&DAT_8012f54c,&local_20,param_3);
      FUN_80047b74(&DAT_8012f54c,&local_20,param_3 + 0x19320);
    }
  }
  return;
}

/* FUN_80164568
 * image   ovl_009aed0 (ovl), base 0x80161cf0
 * address 0x80164568  body 0x80164568..0x801645ff  size 152 B
 * body sha256 131894cedd4d8683cb9fedd161da5c6c60c77bbabac03f36c39957f1ec07ae16
 * provider record sha256 b54bf027b0b83337ba2ea1670a2ee551c81c1a1fcaf0c31675803b906cbcf4e1
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80164568(int param_1)

{
  short sVar1;
  
  sVar1 = func_0x80032d14((int)_DAT_800e115a,(int)_DAT_800e1162,(int)*(short *)(param_1 + 0x2a),
                          (int)*(short *)(param_1 + 0x32));
  if (*(char *)(param_1 + 6) == '\0') {
    if (DAT_800dfbe8 != '\0') {
      func_0x80036c68(param_1,1,3,0);
    }
    func_0x80032ef4(param_1,(int)sVar1,8);
  }
  return;
}

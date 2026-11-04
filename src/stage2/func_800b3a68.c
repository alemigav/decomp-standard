/* func_800b3a68
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b3a68  body 0x800b3a68..0x800b3b9b  size 308 B
 * body sha256 69eba57e15b7f32c5bcaf98558f5c44f842d276b60386f6c354cf2fdf75502d5
 * provider record sha256 debab44b497c62c50d40e02b923c888f5e90d40ada254300d23571f61fa8ec42
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
undefined4
func_800b3a68(int param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4,
             undefined1 param_5)

{
  int iVar1;
  uint uVar2;
  
  if (DAT_80136d80 != '\0') {
    uVar2 = 0;
    iVar1 = -0x7fea74e0;
    do {
      if ((*(char *)(iVar1 + 0x1200) != '\0') && (*(int *)(iVar1 + 0x1224) == param_1))
      goto LAB_800b3ae0;
      uVar2 = uVar2 + 1;
      iVar1 = iVar1 + 0x1228;
    } while (uVar2 < 2);
    uVar2 = 0xffffffff;
LAB_800b3ae0:
    if (uVar2 != 0xffffffff) {
      osRecvMesg(0x8015afa0,0,1);
      iVar1 = uVar2 * 0x1228;
      if (*(int *)(iVar1 + -0x7fea62d4) != -1) {
        func_800a949c(*(undefined4 *)(iVar1 + -0x7fea62d4),param_2,param_3,param_4,param_5);
      }
      *(undefined1 *)(iVar1 + -0x7fea62de) = param_3;
      *(undefined1 *)(iVar1 + -0x7fea62dd) = param_4;
      *(undefined1 *)(iVar1 + -0x7fea62df) = param_2;
      osSendMesg(0x8015afa0,0,0);
      return 1;
    }
  }
  return 0;
}

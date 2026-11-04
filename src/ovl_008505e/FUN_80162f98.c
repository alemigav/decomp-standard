/* FUN_80162f98
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80162f98  body 0x80162f98..0x8016305f  size 200 B
 * body sha256 1fe6d50bb91cf77cd4745aadababa816ee33140fd6e715d7e1cad4f925114992
 * provider record sha256 e56f1785df93353c265847ad6ed2b9cb4e2de27a2f5a7e13290bacaaf8570a9a
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162f98(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = FUN_80163060();
  if (iVar1 < 1) {
    if (iVar1 < 0) {
      if (*(char *)(param_1 + 0x2ba) == '\x02') {
        *(undefined1 *)(param_1 + 5) = 7;
        *(undefined2 *)(param_1 + 6) = 0;
      }
      else {
        *(undefined2 *)(param_1 + 6) = 0x200;
        *(undefined4 *)(param_1 + 0x1e8) = 0x15000f00;
        func_0x80089d54(param_1,param_2,param_3,0x100);
        *(undefined1 *)(param_1 + 0x2be) = 0;
        *(short *)(param_1 + 0x2b6) = *(short *)(param_1 + 0x2b6) + 0x14;
      }
    }
  }
  else {
    func_0x80052bd0(5,0);
    func_0x80052c6c(5,200,0);
  }
  return;
}

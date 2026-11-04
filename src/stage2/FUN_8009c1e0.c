/* FUN_8009c1e0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009c1e0  body 0x8009c1e0..0x8009c28b  size 172 B
 * body sha256 6e89a6e1075a95871c458cea0b8b7059405a381a47b4319157f8ee6955fa562b
 * provider record sha256 a661d88b1b08976284d03c53cae4a239d49e0b6b1e9d46fa275c5a3148a4d6cc
 * callees 3 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8009c1e0(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (param_1[3] != -0x58000000) {
    osCreateMesgQueue(&DAT_80132140,&DAT_80132158,1);
    *(undefined1 *)(param_1 + 1) = 3;
    *(undefined1 *)((int)param_1 + 5) = 5;
    *(undefined1 *)(param_1 + 2) = 0xc;
    *(undefined1 *)((int)param_1 + 6) = 0xd;
    *(undefined1 *)((int)param_1 + 7) = 2;
    param_1[3] = 0xa8000000;
    *(undefined1 *)((int)param_1 + 9) = 1;
    func_0x80006650(param_1 + 5,0x60);
    uVar2 = func_0x8000cd40(1);
    puVar1 = param_1;
    *param_1 = _DAT_8001290c;
    _DAT_8001290c = puVar1;
    func_0x8000cd40(uVar2);
  }
  return;
}

/* FUN_80002360
 * image   boot (boot), base 0x80000480
 * address 0x80002360  body 0x80002360..0x800023d7  size 120 B
 * body sha256 92628cceb1e65cbf7827b7537f5f7e99f2acd963c9ce5f833bc6a93ea96a6f24
 * provider record sha256 66dff96a04ac2b844b3d46927de2441953a973d7f39da505bb6cfc11379d5e11
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80002360(undefined1 param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4,
                 int param_5)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(**(code **)(param_5 + 0x20))(*(undefined4 *)(param_5 + 0x28),1,0x1c);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
    *(undefined1 *)(puVar1 + 4) = param_1;
    *(undefined1 *)((int)puVar1 + 0x11) = param_2;
    puVar1[5] = param_3;
    puVar1[6] = param_4;
  }
  return;
}
